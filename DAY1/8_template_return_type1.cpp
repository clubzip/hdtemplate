#include <iostream>

// add �� ���ø����� ����� ���ô�.

// ��� 1. �Ѱ��� ���ø� ���� 
// => 2���� �Լ� ���ڰ� ���� Ÿ���� �����ؾ� �Ѵ�.
// => �ٸ� Ÿ�� ���޽� "�����Ϸ��� Ÿ�� �߷�" �ȵǹǷ� error
// => ��,Ÿ���� ��������� �����ϸ� ����
template<typename T>
T add(const T& a, const T& b)
{
	return a + b;
}

int main()
{
	std::cout << add(3, 4) << std::endl;
	std::cout << add(3.1, 4.3) << std::endl;

//	std::cout << add(3, 4.3) << std::endl; // error

	std::cout << add<double>(3, 4.3) << std::endl;
}



