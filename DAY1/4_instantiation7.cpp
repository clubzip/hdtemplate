// 4_instantiation7
#include <iostream>

void cleanup()
{
	std::cout << "cleanup" << std::endl;
}

int main()
{
	//....

	// �Լ��� ����Ǳ� ���� cleanup() �� ȣ���ؾ� �Ѵٰ� ������ ���ô�.
	cleanup();
}