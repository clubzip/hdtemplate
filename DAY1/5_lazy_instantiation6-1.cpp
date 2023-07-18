#include <iostream>
#include <type_traits>

// if constexpr �� ���� �θ� ���˴ϴ�.
// => C++17 ����Դϴ�. 

template<typename T>
void fn(T value)
{
	if constexpr (std::is_pointer_v<T>)
		std::cout << "T �� pointer �϶� ����ȭ �˰���" << std::endl;

	else if constexpr( std::is_integral_v<T> )
		std::cout << "T �� ���� �϶� ����ȭ �˰���" << std::endl;
	else
		std::cout << "�����͵� �ƴϰ� ������ �ƴҶ� ����ȭ �˰���" << std::endl;
}

int main()
{
	int n = 10;
	fn(n);
}
