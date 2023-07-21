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

template<typename T> struct result
{
	using type = T;
};

template<typename R, typename ... ARGS >
struct result< R(ARGS...) >
{
	using type = R;
};

template<typename T> void foo(T& a)
{
	// T : int(int, double) 입니다.
	typename result<T>::type n;  
	std::cout << typeid(n).name() << std::endl;
}

int main()
{
	foo(f);	   
}
