#include <iostream>
#include <concepts>

// 1번소스는 "T" 와 "int" 버전을 동시에 제공했습니다.

// C++20 부터는 
// => "정수" 인 경우와 
// => "정수가 아닌" 경우로 오버로딩 가능합니다.


template<typename T> requires std::is_integral_v<T>
T square(T a)
{
	std::cout << "integral" << std::endl;
	return a * a;
}

template<typename T> requires (!std::is_integral_v<T>)
T square(T a)
{
	std::cout << "not integral" << std::endl;
	return a * a;
}

int main()
{
	square(3);
	square(3.4);
	square(3.4f); // float 도 실수 계열이므로 아래 버전 사용

}