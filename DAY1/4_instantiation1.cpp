#include <iostream>

// 15 page

// 핵심 1. 용어 정리
// 인스턴스화(template instantiation)
// => 템플릿으로 부터 실제 "함수/클래스"를 만드는 과정

// 핵심 2. 인스턴스화 방법
// 1. implicit instantiation : 템플릿을 사용하는 코드를 보고 인스턴스화
//    => 타입을 명시적으로 전달하는 경우
//    => 타입을 명시적으로 전달하지 않은 경우.
// 
// 2. explicit instantiation

template<typename T>
T square(T a)
{
	return a * a;
}

int main()
{	
	// 핵심 2. 아래 코드는 모두 암시적 인스턴스화 입니다.
	// 1. 타입을 전달하는 경우
	square<int>(3);
	square<double>(3.3);	
	// 2. 타입을 전달하지 않는 경우
	square(3);				
}

