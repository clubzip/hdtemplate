#include <iostream>

// f1, f2 �� �߿��� �˰����� �ۼ��ߴµ�..
// => ������ �߿��մϴ�.!
void f1(int n) {}
void f2(int n, double d) {}

// �Լ��� ����ð��� �����ϴ� �Լ��� ����� ���ô�.
// => �Ʒ� ó�� ����� ���ڰ� �Ѱ��� �Լ��� ��밡�� �մϴ�.
template<typename F, typename ARG>
void chronometry(F f, ARG arg)
{
	// ========= �ð� ���
	f(arg);   // �Լ� ȣ��
	// ========= ���� �ð� ���
}

int main()
{
	chronometry(f1, 10); // f1(10) �� ����ð��� ������ �޶�� ��
}
