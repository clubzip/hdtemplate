#include <iostream>

// step1. ���� ���� Ŭ���� ���ø�
template<typename ... Types>
struct tuple
{

	static constexpr int N = 0; // �����ϴ� ����� ����.
};

int main()
{
	tuple<> t0;

	tuple<char> t1;
	
	tuple<double, char> t2;
	
	tuple<int, double, char> t3;
}
