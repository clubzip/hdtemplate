#include <iostream>

// ���� ���� �Լ� ���ø�
// => ��� ������ �Լ��� �����Ҽ� �ִ� �ɷ��� �ֽ��ϴ�.
// => godbolt.org �� �Ʒ� �ڵ� �����ؼ� �־� ������
template<typename ... Types> 
void foo(Types ... args)
{

}

// ���� : C����� �������� �Լ���
// => �Ѱ��� �Լ��� ��� ������ ���ڵ� ������ �ִ°�!
void goo(const char* fmt, ...)
{
	// �Ѱ��� �Լ�����.. 
	// �پ��� ���·� ���޵� ���ڸ� ������ �־�� �մϴ�.
	// => �׷��� �� �κ� ȣ���Ҷ� ������ ������ �˷��־�� �մϴ�.
	// => ���ڸ� ������ ���� "va_list, va_arg, va_start" ���� ã�� ������
}
int main()
{
	foo(1);
	foo(1, 2);		  // foo(int, int) �Լ� ����
	foo(1, 3.4, 'A'); // foo(int, double, char) �Լ� ����
					  // Types : int, double, char
					  // args  : 1, 3.4, 'A'

	goo("%d", 1);
	goo("%d %d", 1, 2);
	goo("%d %f %c", 1, 3.4, 'A');
}
