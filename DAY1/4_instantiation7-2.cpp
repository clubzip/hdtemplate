// 4_instantiation7
#include <iostream>

void cleanup()
{
	std::cout << "cleanup" << std::endl;
}

// void(*handler)() : 함수 포인터 타입. 진짜 함수만 등록가능합니다.
//					  함수객체, 람다 표현식등을 등록할수 없습니다.

template<typename T>
class ScopedExit
{
	T handler;
public:
	ScopedExit(const T& f) : handler(f) {}

	~ScopedExit() { handler(); }
};

// convenient function template
// => 함수 인자를 통해서 템플릿 타입을 추론하기 위해 사용했던 기술
template<typename T>
ScopedExit<T> makeScopedExit(const T& f)
{
	return ScopedExit<T>(f);
}
int main()
{
	// C++14..
	ScopedExit<void(*)()> se1(&cleanup);

	// class 템플릿의 타입추론이 안되는 경우 아래 ? 를 채우기가 어렵습니다.
	// => 이럴때 "convenient function template" 으로 하면 됩니다.
	//ScopedExit< ? > se2([]() { std::cout << "lambda" << std::endl; });
	
	auto se2 = makeScopedExit([]() { std::cout << "lambda" << std::endl; });

	// C++17 이라면 class template 도 타입추론이 되므로
	// makeScopedExit 없어도 아래 처럼하면 됩니다.
	ScopedExit se3([]() { std::cout << "lambda" << std::endl; });
}
// github.com/webkit

// source/wtf/wtf/ scopedexit.h 에 위 코드와 유사한 코드 있습니다.
