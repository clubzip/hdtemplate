#include <iostream>

template<typename T>
constexpr int made_year = -1;

// variable template 기술은
// => 대부분 "template specialization" 문법과 같이 사용됩니다.

class Sample
{
};
// Sample 을 만든 사람이 made_year 를 Sample 타입으로 특수화 해서
// 언제 만들었는지 정보(년도)를 알려 줍니다.
template<>
constexpr int made_year<Sample> = 2023;


int main()
{
	std::cout << made_year<int> << std::endl;	
	std::cout << made_year<double> << std::endl;
	std::cout << made_year<Sample> << std::endl;

}



