#include <iostream>

// 방법 3-2. decltype() 을 사용하는 기술 - C++11 기술

// decltype( 표현식 ) : 표현식의 타입을 계산해 달라는 의미

// => 후위 반환 타입(suffix return type, C++11) 기술 필요!

template<typename T1, typename T2>
//decltype(a + b) add(const T1& a, const T2& b) // error, a, b를 선언전에 사용
auto add(const T1& a, const T2& b) -> decltype(a + b) // ok
{
	return a + b;
}

//int main()
auto main() -> int
{
	std::cout << add(3, 4) << std::endl;
	std::cout << add(3.1, 4.3) << std::endl;
	std::cout << add(3, 4.3) << std::endl;

//	a = 20; // error. 변수를 선언전에 사용하고 있습니다
//	int a = 10;
//	a = 20; // ok!!
}



