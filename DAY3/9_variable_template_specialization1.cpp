#include <iostream>

// 일반 전역 변수(상수)
constexpr int made_year1 = -1;


// C++14, variable template
template<typename T>
constexpr int made_year2 = -1;

int main()
{
	// made_year1 은 전역변수이므로 아래 처럼 사용가능합니다.
	std::cout << made_year1 << std::endl;  // -1

	// made_year2 는 인자가 한개인 template 이므로 타입을 전달해야 합니다.
//	std::cout << made_year2 << std::endl;	// error
	std::cout << made_year2<int>    << std::endl;	// ok
	std::cout << made_year2<double> << std::endl;	// ok
	
}



