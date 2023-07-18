#include <iostream>

// 방법 3-1. 반환타입을 템플릿 인자로 받는 기술
// => C++98 시절에 널리 사용했던 기술

// T1, T2 : 인자를 통해서 타입 추론 되지만
// R      : 추론이 안되므로 반드시 전달해야 합니다.
template<typename R, typename T1, typename T2>
R add(const T1& a, const T2& b)
{
	return a + b;
}

int main()
{
	std::cout << add<int>(3, 4) << std::endl;
	std::cout << add<double>(3.1, 4.3) << std::endl;

	std::cout << add<double>(3, 4.3) << std::endl;

}



