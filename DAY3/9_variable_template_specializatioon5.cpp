#include <iostream>
#include <string>
#include <vector>
#include <string_view>
#include <ranges>

int main()
{
	// C++11 의 std::begin() 은 아래 코드가 에러가 아닙니다.
	// => p1 사용시 버그입니다.
	auto p1 = std::begin(std::string("to be or not to be"));

	std::string s1 = "to be or not to be";
	auto p2 = std::begin(std::string_view(s1));


	// C++20 부터 새로운 begin()이 도입됩니다.
//	auto p3 = std::ranges::begin(std::string("to be or not to be"));
					// => error
					// => 자원을 소유하는 타입의 임시객체를 받을수 없도록 설계
		
	auto p4 = std::ranges::begin(std::string_view(s1));
					// => ok
					// => 자원을 대여하는 타입의 임시객체를 받을수 있도록 설계

	// 그렇다면.. 어떤 타입(컨테이너가)이 자원을 소유하는가, 대여하는가 
	// 알아야 합니다.
	// 타입설계자가 알려줘야 합니다.
	// variable template 으로 알려주고 있습니다.
	std::cout << std::ranges::enable_borrowed_range<std::string> << std::endl;
	std::cout << std::ranges::enable_borrowed_range<std::string_view> << std::endl;
}

// enable_borrowed_range는 아래 처럼 되어 있는 변수(상수) 입니다.
template<typename T>
constexpr bool enable_borrowed_range = false;

template<> constexpr bool enable_borrowed_range<std::string_view> = true;
template<> constexpr bool enable_borrowed_range<std::span> = true;