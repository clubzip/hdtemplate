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
	cleanup();
}