// enable_if5 복사 하세요

#include <iostream>
#include <type_traits> 

// enable_if : 정확히 이해하는 "사용하는 것이 어렵지 않지만"
//			   코드가 복잡해 보입니다.

// C++20 에서 enable_if 의 개념을 문법으로 발전 시켰습니다.
// => requires clauses 라는 문법

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


