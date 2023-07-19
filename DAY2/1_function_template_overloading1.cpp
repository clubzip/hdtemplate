#include <iostream>

// 핵심 1. 동일이름의 함수를 
// => template 버전과
// => template 이 아닌 버전(int) 으로 동시 제공 가능합니다

// 사용자가 만든      int square(int) 함수와          => _Z6squarei:
// 템플릿으로 생성된  int square<int>(int) 함수의     => _Z6squareIiET_S0_:
// => 내부 이름은 다릅니다.!!

// godbolt.org 에.. 아래 코드 붙여 넣기 해보세요

template<typename T>
T square(T a)
{
	std::cout << "T" << std::endl;
	return a * a;
}
int square(int a)
{
	std::cout << "int" << std::endl;
	return a * a;
}

int main()
{
	square(3);		// int 버전 사용
	square(3.4);	// 템플릿을 사용해서 square(double) 생성

	square<int>(3);	// T 버전 사용.

	square<>(3);	// T 버전 사용, T의 타입을 3으로 추론.
}



