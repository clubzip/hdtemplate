// square.cpp
#include "square.h"

template<typename T> T square(T a)
{
	return a * a;
}

// ���⿡�� ����� �ν��Ͻ�ȭ�� �س�����
// �ٸ� ���Ͽ��� square ��밡���մϴ�.
template int square(int);
template double square(double);

// ��, �̰�� square(int), square(double) �� ��밡���ϰ�
// �ٸ� Ÿ������ ���� ����!!

