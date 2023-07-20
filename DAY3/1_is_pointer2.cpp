#include <iostream>

// 아래 코드가 T 가 포인터 인지 조사하는 기술 입니다.

template<typename T> struct is_pointer
{
	enum { value = false };
};

template<typename T> struct is_pointer<T*>
{
	enum { value = true };
};

template<typename T> 
void fn(const T& arg)
{
	// 현재 T는 int, int* 
	if (  is_pointer<T>::value  )
		std::cout << "pointer" << std::endl;
	else
		std::cout << "not pointer" << std::endl;
}


int main()
{
	int n = 0;
	fn(n);
	fn(&n);
}
