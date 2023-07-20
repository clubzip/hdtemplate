#include <iostream>
#include <type_traits> 

// printv ���� ��� 4.
// => C++20
// => requires clauses(��) ���

template<typename T> requires std::is_pointer_v<T>
void printv(const T& value)
{
	std::cout << "pointer version : " << value << " : " << *value << std::endl;
}

template<typename T> requires (!std::is_pointer_v<T>)
void printv(const T& value)
{
	std::cout << "not pointer version : " << value << std::endl;
}


int main()
{
	int n = 10;
	printv(&n);
	printv(n);

}


