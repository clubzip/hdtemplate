#include <iostream>
#include <type_traits>

// traits 의 종류
// 1. 타입에 대한 특성을 질의 : std::is_pointer<T>::value    ==> bool 반환
// 2. 변형된 타입 얻기       : std::remove_pointer<T>::type

int main()
{
	// 1. 타입 특성 질의
	bool b = std::is_pointer<int*>::value;

	// 2. 변형된 타입얻기
	std::remove_pointer<int*>::type n; // int

	std::cout << typeid(n).name() << std::endl;
}
