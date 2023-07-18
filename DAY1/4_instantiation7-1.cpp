// 4_instantiation7
#include <iostream>

void cleanup()
{
	std::cout << "cleanup" << std::endl;
}

class ScopedExit
{
	void(*handler)();
public:
	ScopedExit(void(*f)()) : handler(f) {}

	~ScopedExit() { handler(); }
};

int main()
{
	// 함수가 종료될때 실행되어야 하는 함수가 있다면
	// 함수가 시작할때 등록합니다.
	ScopedExit se(&cleanup);

	//... 함수 실행중 "예외" 등이 발생해도 지역변수 se 의 소멸자 
	// 호출은 보장됩니다.
	// 즉, cleanup 함수는 안전하게 호출됩니다.
	
}