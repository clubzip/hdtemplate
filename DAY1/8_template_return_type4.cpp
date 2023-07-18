#include <iostream>

// ��� 3-1. ��ȯŸ���� ���ø� ���ڷ� �޴� ���
// => C++98 ������ �θ� ����ߴ� ���

// T1, T2 : ���ڸ� ���ؼ� Ÿ�� �߷� ������
// R      : �߷��� �ȵǹǷ� �ݵ�� �����ؾ� �մϴ�.
template<typename R, typename T1, typename T2>
R add(const T1& a, const T2& b)
{
	return a + b;
}

int main()
{
	std::cout << add<int>(3, 4) << std::endl;
	std::cout << add<double>(3.1, 4.3) << std::endl;

	std::cout << add<double>(3, 4.3) << std::endl;

}



