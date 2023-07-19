#include <iostream>
#include "fname.h"

// 규칙 3. 인자가 T&& 인경우 - C++11 부터 도입된 기술
// => lvalue 와 rvalue 를 모두 받는 template 만들때 사용
template<typename T> void f3(T&& arg)
{
	std::cout << _FNAME_ << std::endl;
}

int main()
{
	int  n = 10;
	int& r = n;
	const int  c = 10;
	const int& cr = c;

	//							T					T&& arg
	f3(3);	// rvalue전달	int(value type)			int&& arg
	f3(n);	// lvalue전달	int&(reference type)	int& && arg => int& arg
				
	//=> 의도 : lvalue 건 rvalue 건, 모든 인자를 "참조로 받겠다는 의미"
	//         어떤 형태의 인자라도 복사본 만들지 않겠다는 의도!

	// int&& 는 "modern C++" 과정 참고

	// 아래 3개의 인자는 모두 lvalue 입니다.(int&로 받게되므로 const, volatile 유지)
	f3(c);	// c 는 lvalue		T=const int&		arg : const int&
	f3(r);	// T=int&			arg=int&
	f3(cr); // T=const int&		arg=const int&
}

// 3개 규칙 정리 ( 템플릿의 함수 인자 모양에 따라 구분)
// 1. fn(T arg) 
// => fn(exp) 에서 exp 의 const, volatile, reference 를 제거하고 T 타입결정
// 
// 2. fn(T& arg) 
// => fn(exp) 에서 exp 의 const, volatile 는 유지하고, reference 를 제거하고 T 타입결정

// 3. fn(T&& arg) 
// => fn(exp) 에서 exp 가 lvalue 인지 rvalue 인지에 따라 다른 규칙
// rvalue : T=값 타입(int)		T&& = int&&
// lvalue : T=참조타입(int&)		T&& = int& && => int&

// 3번 규칙은 "modern C++ 참고" - lvalue, rvalue



