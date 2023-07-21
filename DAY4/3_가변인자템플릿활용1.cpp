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

// 함수의 반환 타입을 구하는 traits 를 만들어 봅시다.
// 1. primary template 을 만들고 type = T 를 넣습니다.

template<typename T> struct result
{
	using type = T;
};

// 2. 핵심.. 원하는 타입을 얻을수 있도록 부분 특수화 버전을 만듭니다.
// => 이부분이 핵심
/*
template<typename R, typename A1, typename A2>
struct result< R(A1, A2) >
{
	using type = R;
};
*/

// 그런데, 위처럼 만들면 "인자가 2개"인 함수만 사용가능합니다.
// 아래 처럼 가변인자 템플릿으로 하면 "인자의 갯수에 상관없이" 
// 반환 타입 구할수 있습니다.
template<typename R, typename ... ARGS >
struct result< R(ARGS...) >
{
	using type = R;
};

template<typename T> void foo(T& a) 
{
	// T : int(int, double) 입니다.
	typename  :type n;  // int
	std::cout << typeid(n).name() << std::endl;  
}

int main()
{
	foo(f);	   // 인자는 2개, 반환 타입 int
	foo(main); // 인자는 없고, 반환 타입은 int
}
