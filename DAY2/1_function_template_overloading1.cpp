#include <iostream>

// �ٽ� 1. �����̸��� �Լ��� 
// => template ������
// => template �� �ƴ� ����(int) ���� ���� ���� �����մϴ�

template<typename T>
T square(T a)
{
	std::cout << "T" << std::endl;
	return a * a;
}
int square(int a)
{
	std::cout << "int" << std::endl;
	return a * a;
}

int main()
{
	square(3);		// int ���� ���
	square(3.4);	// ���ø��� ����ؼ� square(double) ����

	square<int>(3);	// T ���� ���.

	square<>(3);	// T ���� ���, T�� Ÿ���� 3���� �߷�.
}



