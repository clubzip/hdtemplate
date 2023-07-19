#include <iostream>
#include "fname.h"


// 규칙 1. 함수 인자가 값 타입(call by value) 일때
// => 함수 인자가 가진, const, volatile, reference 속성을 모두 제거하고
//    T의 타입을 결정
template<typename T> void f1(T arg)
{
	// 확인하는 제일 좋은 방법은 "생성된 함수 이름"을 출력 해보세요
	// => 또는 godbolt.org 에서 확인.
	std::cout << _FNAME_ << std::endl;
}

int main()
{
	int  n = 10;
	int& r = n;
	const int  c = 10;
	const int& cr = c;

	f1(n);	// T = int
	f1(c);	// T = int
	f1(r);  // T = int
	f1(cr); // T = int
}