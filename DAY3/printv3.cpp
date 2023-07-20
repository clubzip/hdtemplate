// if_constexpr 3�� �����ϼ���

#include <iostream>
#include <type_traits>

// printv ���� 3.
// => C++17 
// => if constexpr ���

template<typename T>
void printv(const T& value)
{
	if constexpr (std::is_pointer_v<T>)
		std::cout << value << " : " << *value << std::endl;
	else
		std::cout << value << std::endl;
}

int main()
{
	int n = 10;
	printv(&n);
	printv(n);

}



