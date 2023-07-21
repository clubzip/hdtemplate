#include <iostream>
#include <vector>
#include <type_traits>

// Concept 문법
// => 타입이 가져야하는 조건을 코드를 정의 하는 문법
template<typename T>
concept container = requires(T& c)
{
	// 아래 처럼 하면, 멤버 함수 가 있어야 합니다.
	// 즉, 배열은 container 가 아닌 것으로 취급됩니다.
//	c.begin();
//	c.end();

	// std::begin() 은 배열도 받을수 있습니다.
	std::begin(c);
	std::end(c);
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

	check(n); // false
	check(v); // true
	check(x);
}
