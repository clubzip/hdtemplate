// printv2.cpp - enable_if5 �����ϼ���

#include <iostream>
#include <type_traits> 

// printv ���� ��� 2.
// => C++11 
// => std::enable_if �� SFINAE ���� ���

template<typename T>
std::enable_if_t< std::is_pointer_v<T> >   
printv(const T& value)
{
	std::cout << "pointer version : " << value << " : " << *value << std::endl;
}

template<typename T>
std::enable_if_t< !std::is_pointer_v<T> >
printv(const T& value)
{
	std::cout << "not pointer version : " << value << std::endl;
}


int main()
{
	int n = 10;
	printv(&n);
	printv(n);

}

