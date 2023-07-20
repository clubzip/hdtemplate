#include <iostream>
#include <string>
#include <vector>
#include <string_view>
#include <ranges>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// 핵심 1. 반복자를 꺼내는 2가지 방법
	auto it1 = v.begin();		// 멤버 함수 사용. C++98 스타일
								// v가 배열이면 에러

	auto it2 = std::begin(v);	// 일반 함수 사용. C++11 에서 도입
								// v가 배열이라도 가능.

	//--------------------------------------------------

	// 2. rvalue 와 반복자
	auto p1 = std::begin( std::string("to be or not to be") );
				// => 임시객체는 즉시 파괴 되므로 
				// => p1이 가리키는 메모리는 잘못된 메모리 입니다.
				// => 사용하면 안됩니다.

	int n = *p1; // runtime error 가능성 있습니다. 절대 사용금지


	// 아래 코드는 string_view 의 임시객체를 전달합니다.
	std::string s1 = "to be or not to be";
	auto p2 = std::begin( std::string_view(s1) );
			// => std::string_view 도 임시객체지만 자원을 빌려서 사용하는 컨테이너
			// => 반환된 반복자 p2는 안전합니다.!!
	int n2 = *p2; // 안전!!!

}
