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

	gcd(3.1,  5.4);		// double 버전 사용
	gcd(3.1f, 5.4f);	// T 버전 사용. static_assert 가 실패하므로
						// 컴파일 에러!!

	// 핵심
	// static_assert(조건) : 조건을 만족하지 않으면 컴파일 에러
	// => 조건을 만족하지 않으면 에러를 내지 말고, 후보에서 제외될수 없을까?
}
