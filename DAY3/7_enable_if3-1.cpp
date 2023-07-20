#include <iostream>
#include <type_traits>

// enable_if �� ��ȯ Ÿ�Կ� ǥ���ϴ� ���
1. typename std::enable_if< std::is_integral_v<T>, T>::type
2.          std::enable_if_t< std::is_integral_v<T>, T>

// ��ȯ Ÿ�Կ� enable_if �� ����ϴ� ����!!
// => ������ �����Ҷ��� �ش� ���ø��� ����ϰڴٴ� ��

// �Ʒ� �ڵ� �ܿ켼��
std::enable_if_t< ����, ���� Ÿ�� > 

// => ���� Ÿ���� void ��� �Ʒ�ó�� ����ص� �˴ϴ�.
std::enable_if_t< ���� >    // typename T=void �� �ֱ� ������




template<typename T>

std::enable_if_t< std::is_integral_v<T>, T>

gcd(T a, T b)
{
	std::cout << "T" << std::endl;

	return 0;
}






double gcd(double a, double b)
{
	std::cout << "double" << std::endl;
	return 0;
}

int main()
{
	gcd(6, 9);

	gcd(3.1, 5.4);
	gcd(3.1f, 5.4f);
}
