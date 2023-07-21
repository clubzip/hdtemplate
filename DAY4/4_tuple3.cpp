#include <iostream>

// step 3. ������ �����ϱ� !!    �� ������ �ٽ�!!!!

template<typename ... Types>
struct tuple
{
	static constexpr int N = 0;
};

template<typename T, typename ... Types>
struct tuple<T, Types...> : public tuple<Types...>
{
	using base = tuple<Types...>;

	T value;

	tuple() = default;

	tuple(const T& v, const Types& ... args) 
		: value(v), base( args...) {}


	static constexpr int N = base::N + 1;
};




int main()
{
//	tuple<> t0;					 // ���� ���� - primary ���� ���
//	tuple<             char> t1; // char  �� ����
//	tuple<     double, char> t2; // double �� ����

	tuple<int, double, char> t3; // int    �� ����
}
