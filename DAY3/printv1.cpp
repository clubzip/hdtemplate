#include <iostream>
#include <type_traits> 


// printv 구현 방법 1. 
// => std::true_type, std::false_type 을 사용한 오버로딩
// 
// => C++11 의 std::integral_constant 사용하는 기술

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
