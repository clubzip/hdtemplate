// 4_instantiation7
#include <iostream>

void cleanup()
{
	std::cout << "cleanup" << std::endl;
}

// void(*handler)() : �Լ� ������ Ÿ��. ��¥ �Լ��� ��ϰ����մϴ�.
//					  �Լ���ü, ���� ǥ���ĵ��� ����Ҽ� �����ϴ�.

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