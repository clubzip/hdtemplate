#include <iostream>
#include <type_traits>

// 1. T�� ������ �� ���� �ƴ� ��츦 ������ �Լ� ���ø����� �����մϴ�.

template<typename T>
void printv_pointer(const T& value)
{
	std::cout << "pointer version : " << value << " : " << *value << std::endl;
}

template<typename T>
void printv_not_pointer(const T& value)
{
	std::cout << "not pointer version : " << value << std::endl;
}

template<typename T>
void printv(const T& value)
{
	// �Ʒ� �ڵ��� �ǵ�!
	// => template �� ����ؾ߸� �ν��Ͻ�ȭ�� �ȴ�.!!
	// => ���� T �� pointer �� �ƴϸ� printv_pointer ���ø��� ������
	//    �����Ƿ� �ν��Ͻ�ȭ ���� �ʾ������̴�!!!
	// ��� �ǵ�!!! �ε�!!
	if (std::is_pointer_v<T>)
		printv_pointer(value);
	else
		printv_not_pointer(value);
}


int main()
{
	int n = 10;
	printv(&n);
	printv(n);

}


