#include <iostream>
#include <type_traits>
#include <vector>
#include <iterator>
#include <concepts>


// concept ���� �˾ƾ� �ϴ� ��
// 1. concept ����� ��� �˾� �μ���.
template<typename T>
concept container = requires(T & c)
{
	std::begin(c);
	std::end(c);
};

// �Ʒ� 3���� fn �� "requires ����"
// "concept�̸� auto" ���·� �ٽ� ���鷯 ������ => concept3�� ���4ó��

// �Ʒ� container �� ������ �����
void fn(container auto& c)
{
	std::cout << "container" << std::endl;
}

// �Ʒ� std::input_iterator �� C++20 ���� ǥ�ؿ��� �����ϴ� ��
void fn(std::input_iterator auto& c)
{
	std::cout << "iterator" << std::endl;
}

// std::is_integral_v : traits �Դϴ�. �Լ����ø����ڿ� ������������ ����Ҽ� �����ϴ�
// std::integral      : concept �Դϴ�.
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
