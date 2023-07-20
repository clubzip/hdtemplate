#include <iostream>
#include <type_traits>

// ������ �������� ������ �ν��Ͻ�ȭ���� �����ϴ� ����� 
// ��ǥ������ 4������ �ֽ��ϴ�. ( ��� C++ ǥ�ؿ��� ���� )

// 1. std::integral_constant - C++11 ���, ���� �����ϱ� ��ƽ��ϴ�.
// 2. std::enable_if         - C++11 ���, C++20 ������ ���� �θ� ����ߴ� ���
// 3. if constexpr           - C++17 ���, ���� ������ ���
// 4. requires clauses       - C++20 ���, ���� ������ ������ ���..
// 
// �ᱹ, �̷����� 3��, 4���� ����ϰ� �˴ϴ�.!!! 							        



// cppinsights.io ���� �Ʒ� �ڵ� �ٿ��ֱ� �ϼ���
template<typename T>
void printv(const T& value)
{
	if constexpr (std::is_pointer_v<T>)
		std::cout << value << " : " << *value << std::endl;
	else
		std::cout << value << std::endl;
}

int main()
{
	int n = 10;
	printv(&n);
	printv(n);

}


