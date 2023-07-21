#include <iostream>
#include <type_traits>
#include <vector>
#include <iterator>
#include <concepts>


// concept 에서 알아야 하는 것
// 1. concept 만드는 방법 알아 두세요.
template<typename T>
concept container = requires(T & c)
{
	std::begin(c);
	std::end(c);
};

// 아래 3개의 fn 을 "requires 없이"
// "concept이름 auto" 형태로 다시 만들러 보세요 => concept3의 방법4처럼

// 아래 container 는 위에서 만든것
void fn(container auto& c)
{
	std::cout << "container" << std::endl;
}

// 아래 std::input_iterator 는 C++20 부터 표준에서 제공하는 것
void fn(std::input_iterator auto& c)
{
	std::cout << "iterator" << std::endl;
}

// std::is_integral_v : traits 입니다. 함수템플릿인자에 제약조건으로 사용할수 없습니다
// std::integral      : concept 입니다.
// void fn(std::is_integral_v auto& c) // error
void fn(std::integral auto& c)		   // ok 
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
