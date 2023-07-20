// if_constexpr 3번 복사하세요

#include <iostream>
#include <type_traits>

// printv 구현 3.
// => C++17 
// => if constexpr 사용

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



