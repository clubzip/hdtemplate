#include <iostream>
#include <type_traits>

// int2type : 정수형 상수값을 가지고 타입을 만드는 도구
template<int N>
struct int2type
{
	enum { value = N };
};


template<typename T>
void printv_imp(const T& value, int2type<1> )
{
	std::cout << "pointer version : " << value << " : " << *value << std::endl;
}

template<typename T>
void printv_imp(const T& value, int2type<0> )
{
	std::cout << "not pointer version : " << value << std::endl;
}

template<typename T>
void printv(const T& value)
{
	printv_imp(value, int2type< std::is_pointer<T>::value >()  );
	//					0 => int2type<0>
	//					1 => int2type<1>
	//	int2type<0> 은 타입,  "int2type<0>()" 는 임시객체를 만든 것
}


int main()
{
	int n = 10;
	printv(&n);
	printv(n);

}


