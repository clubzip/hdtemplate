// 42 page
#include <iostream>
#include "fname.h"

// type deduction(타입 추론, 타입 연역)
// => 컴파일러가 함수 인자를 보고 T의 타입을 결정하는 원리


template<typename T>
void fn(T arg)
{
	while (--arg) {};
}

int main()
{
	int 	n = 10;
	double 	d = 3.4;
	const int c = 10;

	// 핵심 1. 사용자가 타입을 전달하면 "T" 의 타입은 사용자가 전달한 타입 사용
	fn<int>(3);

	// 핵심 2. 사용자가 타입을 전달하지 않으면
	// => 함수 인자를 보고 컴파일러가 타입을 결정 ( type deduction, type inference)
	fn(n); // T = int 로 결정
	fn(d); // T = double
	fn(c); // T = int ? const int ?
		   // => 답은 int,   
		   // => 컴파일러가 T의 타입을 결정하는 원리는 "3가지 규칙" 이 있습니다.
}