#include <iostream>

// step1. 가변 인자 클래스 템플릿
template<typename ... Types>
struct tuple
{

	static constexpr int N = 0; // 보관하는 요소의 갯수.
};

int main()
{
	tuple<> t0;

	tuple<char> t1;
	
	tuple<double, char> t2;
	
	tuple<int, double, char> t3;
}
