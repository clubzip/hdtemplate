#include <iostream>

// C++17 fold expression 를 사용하는 경우. 
template<typename ... Types>
auto sum1(Types... args)
{
	return (args + ... + 0);
}

// C++17 이전이라면 (C++11/14 시절)
int sum2() { return 0;}

template<typename T, typename ... Types>
auto sum2(T value, Types... args)
{
	return value + sum2(args...); // recursive
}

int main()
{
	auto ret1 = sum1(1, 2, 3, 4, 5);
	auto ret2 = sum2(1, 2, 3, 4, 5);

	std::cout << ret1 << std::endl;
	std::cout << ret2 << std::endl;
}
