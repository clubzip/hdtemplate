#include <iostream>
#include <source_location> // C++20 에서 추가된 헤더.

#include "fname.h"

// fname.h : C++20 지원 안되고 include 가능합니다(조건부 컴파일 사용)
// C++20 지원 되면 : function_name() 사용
//         안되면 : _FNAME_ 매크로 사용

// 파일, 함수의 이름을 얻는 방법
// C 언어 : __FILE__, __LINE__, __func__ 등의 매크로 사용
// C++20 : std::source_location

template<typename T>
T square(T a)
{
	std::string s = function_name(); // "fname.h" 에 있는 함수
				 // function_name(std::source_location::current());

	std::cout << s << std::endl;

	/*
	std::source_location loc = std::source_location::current();
	std::cout << loc.file_name() << std::endl;
	std::cout << loc.line()      << std::endl;
	std::cout << loc.function_name() << std::endl;
	*/
	return a * a;
}

int main()
{
	square<int>(3);
	square<double>(3.3);
	square(3);
}

