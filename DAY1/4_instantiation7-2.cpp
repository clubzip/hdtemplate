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

// convenient template template
// => �Լ� ���ڸ� ���ؼ� ���ø� Ÿ���� �߷��ϱ� ���� ����ߴ� ���
template<typename T>
ScopedExit<T> makeScopedExit(const T& f)
{
	return ScopedExit<T>(f);
}

int main()
{
	// C++14..
	ScopedExit<void(*)()> se1(&cleanup);

	// class ���ø��� Ÿ���߷��� �ȵǴ� ��� �Ʒ� ? �� ä��Ⱑ ��ƽ��ϴ�.
	// => �̷��� "convenient function template" ���� �ϸ� �˴ϴ�.
	//ScopedExit< ? > se2([]() { std::cout << "lambda" << std::endl; });
	
	auto se2 = makeScopedExit([]() { std::cout << "lambda" << std::endl; });
}

