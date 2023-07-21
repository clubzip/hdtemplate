#include <iostream>
#include <vector>
#include <type_traits>

// Concept ����
// => Ÿ���� �������ϴ� ������ �ڵ带 ���� �ϴ� ����
template<typename T>
concept container = requires(T& c)
{
	// �Ʒ� ó�� �ϸ�, ��� �Լ� �� �־�� �մϴ�.
	// ��, �迭�� container �� �ƴ� ������ ��޵˴ϴ�.
//	c.begin();
//	c.end();

	// std::begin() �� �迭�� ������ �ֽ��ϴ�.
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
