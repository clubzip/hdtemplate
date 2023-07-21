#include <iostream>
#include <type_traits>
#include <vector>
#include <iterator>
#include <concepts>


// concept 에서 알아야 하는 것
// 1. concept 만드는 방법 알아 두세요.
template<typename T>
concept container = requires(T& c)
{
	std::begin(c);
	std::end(c);
};

// 2. 만들어진 concept 을 활용하는 법
// 
// 2.1. traits 처럼 조사하는 용도로 사용
// =>  if constexpr ( container<T> )


// 2.2 template require clauses

// => 조건을 만족할때만 template 을 사용하겠다.
// => 조건은 컴파일 시간에 결정되는 "bool값" 이면 어떤것도 가능
// => 대부분 concept 과 type traits 사용

// # 위에서 만든 concept 사용
template<typename T> requires container<T> 
void fn(T& c) 
{
	std::cout << "container" << std::endl;
}

// # C++ 20 표준에 이미 만들어진 많은 concept 이 있습니다.(100여개)
template<typename T> requires std::input_iterator<T>
void fn(T& c)
{
	std::cout << "iterator" << std::endl;
}

// # C++11 type_traits 도 사용가능
template<typename T> requires std::is_integral_v<T>
void fn(T& c)
{
	std::cout << "integer" << std::endl;
}

int main()
{
	int n = 10;
	std::vector<int> v = { 1,2,3 };
	
	auto p = v.begin();

	fn(v); // container
	fn(p); // iterator
	fn(n); // integer
}
