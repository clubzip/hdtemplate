#include <iostream>
#include <string>
#include <vector>
#include <string_view>
#include <ranges>

int main()
{
	// C++11 �� std::begin() �� �Ʒ� �ڵ尡 ������ �ƴմϴ�.
	// => p1 ���� �����Դϴ�.
	auto p1 = std::begin(std::string("to be or not to be"));

	std::string s1 = "to be or not to be";
	auto p2 = std::begin(std::string_view(s1));


	// C++20 ���� ���ο� begin()�� ���Ե˴ϴ�.
//	auto p3 = std::ranges::begin(std::string("to be or not to be"));
					// => error
					// => �ڿ��� �����ϴ� Ÿ���� �ӽð�ü�� ������ ������ ����
		
	auto p4 = std::ranges::begin(std::string_view(s1));
					// => ok
					// => �ڿ��� �뿩�ϴ� Ÿ���� �ӽð�ü�� ������ �ֵ��� ����

	// �׷��ٸ�.. � Ÿ��(�����̳ʰ�)�� �ڿ��� �����ϴ°�, �뿩�ϴ°� 
	// �˾ƾ� �մϴ�.
	// Ÿ�Լ����ڰ� �˷���� �մϴ�.
	// variable template ���� �˷��ְ� �ֽ��ϴ�.
	std::cout << std::ranges::enable_borrowed_range<std::string> << std::endl;
	std::cout << std::ranges::enable_borrowed_range<std::string_view> << std::endl;
}

// enable_borrowed_range�� �Ʒ� ó�� �Ǿ� �ִ� ����(���) �Դϴ�.
template<typename T>
constexpr bool enable_borrowed_range = false;

template<> constexpr bool enable_borrowed_range<std::string_view> = true;
template<> constexpr bool enable_borrowed_range<std::span> = true;