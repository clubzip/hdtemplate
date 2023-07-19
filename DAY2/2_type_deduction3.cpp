#include <iostream>
#include "fname.h"

// 규칙 2. 함수 인자가 reference (T&) 일때 
// => 함수 인자가 가진 reference 속성만 제거 하고 타입을 결정한다.
// => 함수 인자가 가진 const,volatile 을 유지해야 한다.
template<typename T> void f2(T& arg)
{
	std::cout << _FNAME_ << std::endl;
}

int main()
{
	int  n = 10;
	int& r = n;
	const int  c = 10;
	const int& cr = c;

	f2(n);	// T=int,		arg=int&
	f2(c);	// T=const int  arg=const int&
	f2(r);  // T=int		arg=int&
	f2(cr); // T=const int  arg=const int&
}