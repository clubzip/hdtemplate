#include <iostream>
#include <type_traits>

// if constexpr 은 아주 널리 사용됩니다.
// => C++17 기술입니다. 

template<typename T>
void fn(T value)
{
	if constexpr (std::is_pointer_v<T>)
		std::cout << "T 가 pointer 일때 최적화 알고리즘" << std::endl;

	else if constexpr( std::is_integral_v<T> )
		std::cout << "T 가 정수 일때 최적화 알고리즘" << std::endl;
	else
		std::cout << "포인터도 아니고 정수도 아닐때 최적화 알고리즘" << std::endl;
}

int main()
{
	int n = 10;
	fn(n);
}
