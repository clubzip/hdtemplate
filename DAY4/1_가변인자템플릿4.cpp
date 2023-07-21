#include <iostream>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}

template<typename ... Types> void foo(Types ... args)
{
	// args : 1, 2, 3

	// args 안의 있는 모든 요소를 화면에 출력하고 싶다.
//	printv(args...);	// printv(1, 2, 3) 의 의미.
						// printv 는 인자가 한개 이므로 error

//	printv(args)...;	// printv(1), printv(2), printv(3) 의 의도인데..
						// error 입니다.
						// 이 위치 에서는 pack expansion 될수 없습니다.

	// 핵심 1. pack expansion 이 가능한 위치
	// 1. 함수 호출시 () 안 : goo(args...)
	// 2. {} 초기화 구문 안 : int x[] = {args...}
	// 3. template 인자 <>  : tuple<Types...>

//	args...;               // error. pack expansion 이 가능한 위치 아님.
//	int x[] = { args... }; // ok..  {} 초기화 안에서는 가능
						
	// 그래서 args 의 모든 요소를 printv 에 각각 보내려면
//	printv(args)...; 이렇게는 안되고..

	int dummy[]  = { 0, (printv(args), 0)... }; 
				// { 0, (printv(1), 0), (printv(2), 0), (printv(3), 0) }

	// => 위 코드는 "C++11 때 가변 인자 처음 등장하고 소개 되었던 코드 입니다."
	// => 지금은 C++17 의 "fold" 기술로 하면 간단하게 할수 있습니다.

	// 이소스의 핵심 : pack expansion 은 모든 위치에서 가능한것은 아니다!!!
}

int main()
{
	foo(1, 2, 3);
	foo();
}

