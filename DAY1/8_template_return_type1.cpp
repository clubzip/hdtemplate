#include <iostream>

// add 를 템플릿으로 만들어 봅시다.

// 방법 1. 한개의 템플릿 인자 
// => 2개의 함수 인자가 같은 타입을 전달해야 한다.
// => 다른 타입 전달시 "컴파일러가 타입 추론" 안되므로 error
// => 단,타입을 명시적으로 전달하면 가능
template<typename T>
T add(const T& a, const T& b)
{
	return a + b;
}

int main()
{
	std::cout << add(3, 4) << std::endl;
	std::cout << add(3.1, 4.3) << std::endl;

//	std::cout << add(3, 4.3) << std::endl; // error

	std::cout << add<double>(3, 4.3) << std::endl;
}



