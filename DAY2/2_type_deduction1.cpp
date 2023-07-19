// 42 page
#include <iostream>
#include "fname.h"

// type deduction(Ÿ�� �߷�, Ÿ�� ����)
// => �����Ϸ��� �Լ� ���ڸ� ���� T�� Ÿ���� �����ϴ� ����


template<typename T>
void fn(T arg)
{
	while (--arg) {};
}

int main()
{
	int 	n = 10;
	double 	d = 3.4;
	const int c = 10;

	// �ٽ� 1. ����ڰ� Ÿ���� �����ϸ� "T" �� Ÿ���� ����ڰ� ������ Ÿ�� ���
	fn<int>(3);

	// �ٽ� 2. ����ڰ� Ÿ���� �������� ������
	// => �Լ� ���ڸ� ���� �����Ϸ��� Ÿ���� ���� ( type deduction, type inference)
	fn(n); // T = int �� ����
	fn(d); // T = double
	fn(c); // T = int ? const int ?
		   // => ���� int,   
		   // => �����Ϸ��� T�� Ÿ���� �����ϴ� ������ "3���� ��Ģ" �� �ֽ��ϴ�.
}