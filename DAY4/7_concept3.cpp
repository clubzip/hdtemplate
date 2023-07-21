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

// requires 절을 표기하는 다양한 방법
// 1. 기본 표기법
template<typename T> requires container<T>
void f1(T& c)
{
	std::cout << "container" << std::endl;
}

// 2. 함수 () 뒤에 있어도 됩니다.
template<typename T> 
void f2(T& c) requires container<T>
{
	std::cout << "container" << std::endl;
}

// 3. typename 대신, concept 이름 가능합니다. 위 코드와 완전히동일
template<container T>
void f3(T& c) 
{
	std::cout << "container" << std::endl;
}

// 4. template 없이 "concept_이름 auto" 로 표기 가능
void f4(container auto& c)
{
	std::cout << "container" << std::endl;
}

// 5. 4번에서 concept 이름 없이 auto 만 적으로 
// => 제약 조건이 없는 템플릿이 되는 것!
void f5(auto& c)
{
	std::cout << "container" << std::endl;
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
