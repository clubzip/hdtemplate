#include <iostream>

// step 2. �Ѱ� �����ϱ�

template<typename ... Types>
struct tuple
{
	static constexpr int N = 0; 
};

// tuple ���� �ּ� �Ѱ��̻��� Ÿ���� �ִ� ��츦 ���� �κ� Ư��ȭ
template<typename T, typename ... Types>
struct tuple<T, Types...>
{
	T value;

	tuple() = default;
	tuple(const T& v) : value(v) {}

	static constexpr int N = 1;
};



int main()
{
	tuple<> t0;

	tuple<char> t1;
	tuple<double, char> t2;
	tuple<int, double, char> t3;
}
