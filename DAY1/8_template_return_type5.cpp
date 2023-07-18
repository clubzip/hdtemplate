#include <iostream>

// ��� 3-2. decltype() �� ����ϴ� ��� - C++11 ���

// decltype( ǥ���� ) : ǥ������ Ÿ���� ����� �޶�� �ǹ�

// => ���� ��ȯ Ÿ��(suffix return type, C++11) ��� �ʿ�!

template<typename T1, typename T2>
//decltype(a + b) add(const T1& a, const T2& b) // error, a, b�� �������� ���
auto add(const T1& a, const T2& b) -> decltype(a + b) // ok
{
	return a + b;
}

//int main()
auto main() -> int
{
	std::cout << add(3, 4) << std::endl;
	std::cout << add(3.1, 4.3) << std::endl;
	std::cout << add(3, 4.3) << std::endl;

//	a = 20; // error. ������ �������� ����ϰ� �ֽ��ϴ�
//	int a = 10;
//	a = 20; // ok!!
}



