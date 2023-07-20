#include <iostream>
#include <type_traits>

// enable_if 를 반환 타입에 표기하는 방법
1. typename std::enable_if< std::is_integral_v<T>, T>::type
2.          std::enable_if_t< std::is_integral_v<T>, T>

// 반환 타입에 enable_if 를 사용하는 이유!!
// => 조건을 만족할때만 해당 템플릿을 사용하겠다는 것

// 아래 코드 외우세요
std::enable_if_t< 조건, 리턴 타입 > 



template<typename T>

std::enable_if_t< std::is_integral_v<T>, T>

gcd(T a, T b)
{
	std::cout << "T" << std::endl;

	return 0;
}






double gcd(double a, double b)
{
	std::cout << "double" << std::endl;
	return 0;
}

int main()
{
	gcd(6, 9);

	gcd(3.1, 5.4);
	gcd(3.1f, 5.4f);
}
