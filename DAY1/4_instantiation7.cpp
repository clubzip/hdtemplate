// 4_instantiation7
#include <iostream>

void cleanup()
{
	std::cout << "cleanup" << std::endl;
}

int main()
{
	//....

	// 함수가 종료되기 전에 cleanup() 을 호출해야 한다고 생각해 봅시다.
	cleanup(); // 어떤 자원을 관리하는 코드는 함수에 끝에서 직접 호출
				// 하는 것은 좋은 코드가 아닙니다.
				// 함수 실행중간에 "예외"등의 상황이 발생하면 
				// cleanup 은 실행될수 없습니다.
}