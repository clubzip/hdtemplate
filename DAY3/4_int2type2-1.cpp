#include <iostream>
#include <type_traits>


template<typename T>
void printv_imp(const T & value, YES )
{
	std::cout << "pointer version : " << value << " : " << *value << std::endl;
}

template<typename T>
void printv_imp(const T & value, NO)
{
	std::cout << "not pointer version : " << value << std::endl;
}

template<typename T>
void printv(const T& value)
{
	// 함수 오버로딩을 사용해서 조건에 따라서 "다른 함수"를 호출합니다.
	printv_imp(value, std::is_pointer<T>::value  );
						// T 포인터라면   : true 즉, 1
						// T 포인터아니면 : false 즉, 0
}


int main()
{
	int n = 10;
	printv(&n);
	printv(n);

}


