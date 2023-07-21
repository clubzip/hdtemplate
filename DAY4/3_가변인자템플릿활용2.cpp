#include <iostream>

// 함수의 반환 타입 구하기

// 핵심 1. 변수(또는 함수)선언문에서 이름만 제거하면 "타입" 이 됩니다.

// 함수 f 도 타입이 있습니다. 
// f의 타입 : int(int, double) 

int f(int a, double b)
{
	return 0;
}

//---------------------------------------------

template<int N, typename T> struct argument
{
	using type = T;
};

// 핵심 : 원하는 정보(함수의 인자 타입)을 얻을수 있도록 부분 특수화 하는 것이
//        핵심 입니다.
/*
template<int N, typename R, typename ... ARGS> 
struct argument< N, R(ARGS...)>
{
	// 여기에서 "T 타입의 함수에서 N 번째 인자 타입"을 구할수 있을까요 ?
	// => 구할수 없습니다.잘못된 부분 특수화
	using type = ?;
};
*/

/*
// N == 0 일때를 먼저 구합니다.
template<typename R, typename ... ARGS>
struct argument< 0, R(ARGS...)>
{
	// 여기에서 "T 타입의 함수에서 0 번째 인자 타입"을 구할수 있을까요 ?
	// => 역시 구할수 없습니다.잘못된 부분 특수화
	using type = ? ;
};
*/

// N == 0 일때를 먼저 구합니다.
template<typename R, typename A1, typename ... ARGS>
struct argument< 0, R(A1, ARGS...) >
{
	// 이제, 0번째 인자 타입을 표기할수 있게 되었습니다.
	using type = A1 ;
};
// 이제 N != 0 일때만 구하면 됩니다.
template<int N, typename R, typename A1, typename ... ARGS>
struct argument< N, R(A1, ARGS...) >
{
	// f(int, double, char) 의 1번째 인자는 "double" 입니다.
	// f(     double, char) 의 0번째 인자는 "double" 입니다.
	// => 즉, N번째 인자는 인자한개를 제거하고 N-1 번째를 구하면 됩니다.

	using type = typename argument<N-1, R(ARGS...)>::type ;
};

template<typename T> void foo(T& a)
{
	// T : int(int, double) 입니다.
//	typename argument<0, T>::type n;  // int
	typename argument<1, T>::type n;  // double

	std::cout << typeid(n).name() << std::endl;
}

int main()
{
	foo(f);	   
}
