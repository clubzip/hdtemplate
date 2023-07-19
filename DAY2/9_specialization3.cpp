#include <iostream>

// 핵심 : 문법 연습
// => 실전 코드는 아니고,, 문법 연습!!

template<typename T, typename U> struct Object
{
	static void fn() { std::cout << "T, U" << std::endl; }
};

// T*, U*.. 즉, 2개 인자가 모두 포인터 일때를 위한 부분 특수화
template<typename T, typename U> struct Object<T*, U*>
{
	static void fn() { std::cout << "T*, U*" << std::endl; }
};

// T*, U
template<typename T, typename U> struct Object<T*, U>
{
	static void fn() { std::cout << "T*, U" << std::endl; }
};

// 아래 코드가 핵심 입니다.
// primary template 의 템플릿 인자가 2개 일때 Object<T, U>

// 1. Object 사용자는 반드시 인자를 2개 전달해야 합니다. : Object<char, double>

// 2. 부분 특수화 모양은 반드시 2개를 표기 해야 합니다.  : Object<T, T>

// 3. 부분 특수화의 템플릿 인자 갯수는 "2개" 가 아니어도 됩니다.

template<typename T> struct Object<T, T>
{
	static void fn() { std::cout << "T, T" << std::endl; }
};

// int, U
template<typename U> struct Object<int, U>
{
	static void fn() { std::cout << "int, U" << std::endl; }
};

// int, short
// 타입이 확정 되었으므로 "부분 특수화"가 아닌 특수화(specialization) 입니다.
template<> struct Object<int, short>
{
	static void fn() { std::cout << "int, short" << std::endl; }
};

int main()
{
	Object<char, double>::fn();	  // T, U
	Object<char*, double*>::fn(); // T*, U*	
	Object<short*, double>::fn(); // T*, U
	Object<float,  float>::fn();  // T, T
	Object<int,    float>::fn();  // int, U
	Object<int, short>::fn();	  // int, short

	// 위 코드 이해 되신분은 아래 코드 실행되게 해보세요
	Object<double, Object<int, char>>::fn();
						// Object<T, Object<U, V>> 라고 출력하세요
}
// T* : 포인터 일때
// U : 임의의 타입(포인터 일수도 있고, 아닐수도 있고)