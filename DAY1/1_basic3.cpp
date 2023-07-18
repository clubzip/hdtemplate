#include <iostream>

// template instantiation(템플릿 인스턴스화)
// => 템플릿(틀) 로 부터 실제 "함수/클래스"를 만드는 과정
// => 컴파일 시간에 컴파일러가 수행.

// 핵심 : 인스턴스화의 결과를 확인하는 방법
// 1. godbolt.org    => 가장 권장하는 방법(단, 어셈블리언어로 확인)
// 2. cppinsights.io => 어셈이 아닌 C++언어로 확인 가능


// 3. 함수 이름을 출력해 보는 방법
//    => 매크로 사용 ( __FUNCSIG__, __PRETTY_FUNCTION__)
//    => C++20 std::source_location 사용


#include "fname.h" // 이 안에 _FNAME_ 있습니다.

template<typename T>
T square(T a)
{	
	// __func__ : 함수 이름을 담은 표준 매크로. 
	//			  단, 이름만 출력, 인자가 포함 안됨..

	// std::cout << __func__ << std::endl;

	// __FUNCSIG__ : 함수이름 + 함수시그니쳐(리턴 타입, 인자), vs 만 가능
	// __PRETTY_FUNCTION__ : g++ 전용
	
	// std::cout << __FUNCSIG__ << std::endl;
	// std::cout << __PRETTY_FUNCTION__ << std::endl;
	
	std::cout << _FNAME_ << std::endl;


	return a * a;
}

int main()
{
	square<int>(3);			
	square<double>(3.3);
	square(3);
}

