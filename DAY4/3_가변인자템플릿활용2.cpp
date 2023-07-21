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

template<int N, typename R, typename ... ARGS> 
struct argument< N, R(ARGS...)>
{
	// 여기에서 T 타입의 함수에서 N 번째 타입을 구할수 있을까요 ?
	using type = ?;
};



template<typename T> void foo(T& a)
{
	// T : int(int, double) 입니다.
	typename argument<0, T>::type n;  // int

	std::cout << typeid(n).name() << std::endl;
}

int main()
{
	foo(f);	   
}
