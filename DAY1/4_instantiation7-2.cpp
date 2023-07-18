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
int main()
{
	// C++14..
	ScopedExit<void(*)()> se1(&cleanup);

	ScopedExit< ? > se2([]() { std::cout << "lambda" << std::endl; });

}