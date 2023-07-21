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

// 결국 argument 는 아래 2개의 부분 특수화면 사용하게 됩니다.
// 이럴때는 보통 primary version 을 선언만 하세요
template<int N, typename T> struct argument;


template<typename R, typename A1, typename ... ARGS>
struct argument< 0, R(A1, ARGS...) >
{
	using type = A1;
};

template<int N, typename R, typename A1, typename ... ARGS>
struct argument< N, R(A1, ARGS...) >
{
	using type = typename argument<N - 1, R(ARGS...)>::type;
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
