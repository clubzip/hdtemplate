#include <iostream>

template<typename T>
void printv(const T& value)
{
	if ( T 의 타입이 포인터 타입 이면 )
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

