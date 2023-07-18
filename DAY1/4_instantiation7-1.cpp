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
	// �Լ��� ����ɶ� ����Ǿ�� �ϴ� �Լ��� �ִٸ�
	// �Լ��� �����Ҷ� ����մϴ�.
	ScopedExit se(&cleanup);

	//... �Լ� ������ "����" ���� �߻��ص� �������� se �� �Ҹ��� 
	// ȣ���� ����˴ϴ�.
	// ��, cleanup �Լ��� �����ϰ� ȣ��˴ϴ�.
	
}