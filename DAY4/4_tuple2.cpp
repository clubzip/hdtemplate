#include <iostream>

// step 2. 한개 보관하기

template<typename ... Types>
struct tuple
{
	static constexpr int N = 0; 
};

// tuple 사용시 최소 한개이상이 타입이 있는 경우를 위한 부분 특수화
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
