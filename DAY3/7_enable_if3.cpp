#include <iostream>
#include <type_traits>


// std::enable_if<bool값, 타입>::type    의 의미를 생각해 보세요

template<typename T> 
						// T가 정수라면 true     ::type 는 T, 즉 반환타입은 T
typename std::enable_if< std::is_integral_v<T>, T>::type
						// T가 정수가 아니면 false  ::type 가 없다. 
						// 즉, 함수 생성 실패, 하지만 SFINAE 규칙 때문에
						// 에러가 아니고 후보에서 제외!
gcd(T a, T b)
{
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
