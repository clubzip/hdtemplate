#include <iostream>
#include <vector>
#include <type_traits>

// Concept 문법
// => 타입이 가져야하는 조건을 코드를 정의 하는 문법
template<typename T>
concept container = requires(T c)
{

};


template<typename T> void check(T& c)
{
	bool b = container<T>;

	std::cout << b << std::endl;
}



int main()
{
	int n = 0;
	std::vector<int> v = { 1,2,3 };
	int x[3] = { 1,2,3 };

	check(n);
	check(v);
	check(x);
}
