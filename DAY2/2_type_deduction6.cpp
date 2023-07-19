#include <iostream>
#include "fname.h"

// 핵심 : template 과 배열 인자

template<typename T> void f1(T arg)
{
	std::cout << _FNAME_ << std::endl;
}

template<typename T> void f2(T& arg)
{
	std::cout << _FNAME_ << std::endl;
}

int main()
{
	int x[3] = { 1,2,3 };

//	int y[3] = x; // error. 배열은 복사 할수 없습니다.
	int* p = x;   // ok     배열의 이름은 배열의 1번째 요소의 주소로 암시적
				  //		변환가능

	int(&r)[3] = x; // ok. 배열을 가리키는 참조는 만들수 있습니다.

	// 위 3줄을 참고해서 아래 코드를 생각해 보세요
	// x : int[3] 
	f1(x);	// 1. f1(int arg[3] )로 결정했다면, 배열을 복사하는 코드가 됩니다. 에러!
			// 2. f1(int* arg) 로 결정했다면 에러 아님. => 그래서 이모양으로 생성

	f2(x);	// T = int[3],  arg = int(&)[3]
			// f2( int(&arg)[3] )

	// 정리. 배열을 템플릿에 전달할때
	// 값으로 받으면 T=포인터
	// 참조로 반으면 T=배열
	f1(x);	// T=int*		arg=int*
	f2(x);	// T=int[3]		arg=int(&)[3]
}
