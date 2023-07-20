#include <iostream>

// traits 기술 정리

// 핵심 1. 헤더 파일은 "<type_traits>", C++11
#include <type_traits>

// C++14 부터 아래처럼 using template 이 표준에서 제공됩니다.
/*
template<typename T>
using remove_pointer_t = typename std::remove_pointer<T>::type;
*/

template<typename T>
void fn(const T& arg)
{
	// 핵심 2. 타입의 특성 조사 
	// => std::is_xxxx<T>::value 형태
	bool b1 = std::is_pointer<T>::value; // C++11 스타일
	bool b2 = std::is_pointer_v<T>;		 // C++17 부터 제공하는 스타일
										 // 일부 컴파일러는 C++14에서도 가능

	// 핵심 3. 변형 타입얻기
	typename std::remove_pointer<T>::type n1; // C++11 style
	std::remove_pointer_t<T> n2;	// C++14 style

//	std::remove_
}

int main()
{
	int n = 0;
	fn(&n);
}
