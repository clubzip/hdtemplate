#include <iostream>
#include <type_traits> 


// printv ���� ��� 1. 
// => std::true_type, std::false_type �� ����� �����ε�
// 
// => C++11 �� std::integral_constant ����ϴ� ���

template<typename T>
void printv_imp(const T& value, std::true_type)
{
	std::cout << "pointer version : " << value << " : " << *value << std::endl;
}

template<typename T>
void printv_imp(const T& value, std::false_type)
{
	std::cout << "not pointer version : " << value << std::endl;
}

template<typename T>
void printv(const T& value)
{
	printv_imp(value, std::is_pointer<T>());
}
int main()
{
	int n = 10;
	printv(&n);
	printv(n);

}
