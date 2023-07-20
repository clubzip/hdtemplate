#include <iostream>
#include <type_traits>

// 1. T가 포인터 인 경우와 아닌 경우를 별도의 함수 템플릿으로 제공합니다.

template<typename T>
void printv_pointer(const T& value)
{
	std::cout << "pointer version : " << value << " : " << *value << std::endl;
}

template<typename T>
void printv_not_pointer(const T& value)
{
	std::cout << "not pointer version : " << value << std::endl;
}

template<typename T>
void printv(const T& value)
{
	// 아래 코드의 의도!
	// => template 은 사용해야만 인스턴스화가 된다.!!
	// => 따라서 T 가 pointer 가 아니면 printv_pointer 템플릿은 사용되지
	//    않으므로 인스턴스화 되지 않았을것이다!!!
	// 라는 의도!!! 인데!!
	if (std::is_pointer_v<T>)		// 컴파일 할때 if ( false )로 결정되어도
		printv_pointer(value);		// 이 함수 템플릿은 instance 화 됩니다.
	else
		printv_not_pointer(value);
}
int main()
{
	int n = 10;
	printv(&n);
	printv(n);

}


