#include <iostream>
#include <string>
#include <string_view>	// C++17 에서 추가됨










int main()
{
	std::string s1 = "to be or not to be";

	// 아래 2줄을 차이를 꼭 알아 두세요.
	std::string      s2 = s1;	// s2 가 s1 의 문자열을 깊은 복사
	std::string_view sv = s1;	// sv 가 s1 의 문자열 포인터만 보관
								// sv가 s1의 문자열을 빌려서(borrow) 사용

	// string      : 자원 소유
	// string_view : 자원 소유 안함

}

