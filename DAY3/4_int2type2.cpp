#include <iostream>
#include <type_traits>

// ���ǿ� ���� �ٸ� �Լ��� ȣ���ϴ� ���
// 1. if ���ǹ� ��� : ����ð��� ���� ������ �Լ� ȣ���� ������..
//					  if (false) �� ����� �Լ� ���ø���.. �ν��Ͻ�ȭ ��..
// 
// 2. �Լ� �����ε�  : ������ �ð��� �Լ� ȣ���� ������..
//					  ������ ���� �Լ� ���ø��� �ν��Ͻ�ȭ�� ���� �ȵ� 	

template<typename T> void f(T, int) {}    // A
template<typename T> void f(T, double) {} // B

f(value, 3.3);	// B ���..
				// A�� ���� ���� �����Ƿ� �ν��Ͻ�ȭ�� ���� �ȵ�.

if (false)
	f(value, 1);	// �� ���� ������� ������, �ν��Ͻ�ȭ�� ���Ե�
else 
	f(value, 3.3);








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


