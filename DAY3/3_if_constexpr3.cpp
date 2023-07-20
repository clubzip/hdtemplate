#include <iostream>
#include <type_traits>

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


