// is_pointer1.cpp 복사
#include <iostream>
#include <type_traits>

// 아래 코드가 왜?? 에러인지 잘 생각해 보세요..
template<typename T>
void printv(const T& value)
{
	if ( std::is_pointer_v<T> )
		std::cout << value << " : " << *value << std::endl;
	else
		std::cout << value << std::endl;
}
int main()
{
	int n = 10;
	printv(&n);
	printv(n);	// <==== 이렇게 사용시 에러 입니다.
}


