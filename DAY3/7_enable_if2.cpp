#include <iostream>
#include <type_traits>

// 최대 공약수를 구하는 함수를 생각해 봅시다.( 함수 세부 구현은 생략..)
template<typename T> T gcd(T a, T b) 
{
	static_assert(std::is_integral_v<T>, "Error T is not integer");
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

	gcd(3.1,  5.4);		
}
