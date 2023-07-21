#include <iostream>
#include <algorithm>
#include <concepts>
#include <vector>


template<typename IT, typename T>
	requires (!std::predicate<T, typename IT::value_type>)
IT xfind(IT first, IT last, T value)
{
	std::cout << "값 버전" << std::endl;
	return first;
}

// std::predicate<F, T1>     : F(T1) 형태로 실행가능한 함수 인가 ??
// std::predicate<F, T1, T2> : F(T1, T2) 형태로 실행가능한 함수 인가 ??

template<typename IT, typename Pred> 
					requires std::predicate<Pred, typename IT::value_type>
IT xfind(IT first, IT last, Pred value)
{
	std::cout << "조건자 버전" << std::endl;

	return first;
}

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };


	auto p1 = xfind(std::begin(v), std::end(v), 3);
	auto p2 = xfind(std::begin(v), std::end(v), [](int a) { return a % 3 == 0; });

}
