#include <iostream>

// 핵심 : 템플릿은 2번 컴파일 됩니다.

// 1. 템플릿 자체를 컴파일 합니다. 
//    => T와는 관련없이 코드에 오류가 있는지 검사합니다.

// 2. 인스턴스화된 함수를 다시 컴파일 합니다.

// 컴파일 하지 말고, 현재 코드에서 에러를 모두 찾아 보세요

template<typename T>
void foo(T arg)
{
//	goo();		// 에러. goo() 함수가 없습니다.

	goo(arg);
}

int main()
{

}

