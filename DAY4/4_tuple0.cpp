#include <tuple>
#include <vector>
#include <iostream>

int main()
{
	// vector : "동일한 타입" 을 여러개 보관
	std::vector<int> v{1,2,3};
	

	// pair : "서로 다른 타입" 을 "2개" 보관
	std::pair<int, double> p1(1, 3.4);


	// pair 에 2개 이상 보관도 가능합니다.
	// => 하지만, 코드가 복잡해 보입니다.
	std::pair<int, std::pair<double, char>> p3(1, { 3.4, 'A' });


	// C++11에서 도입된 std::tuple 은 서로 다른 타입을 여러개 보관가능합니다.
	std::tuple<int, double, char> t3(1, 3.4, 'A');

	// 각 요소 접근은 std::get 사용
	std::get<0>(t3) = 99;

	std::cout << std::get<1>(t3) << std::endl;
}

std::tuple<int, double> foo()
{
	// int, double 값을 반환 하고 싶다.
	// 1. 구조체를 만들어서 사용
	// 2. tuple 사용.
	return std::make_tuple(1, 3.4);
}

// 점을 표현, 사각형을 표현 : 데이타 묶음이 의미가 있으므로  구조체로 설계