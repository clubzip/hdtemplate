#include <iostream>

// explicit instantiation 

template<typename T>
T square(T a)
{
	return a * a;
}

// ����ϴ� �ڵ带 ���� �ν��Ͻ�ȭ�� ���� ����
// ��������� �ν��Ͻ�ȭ �ش޶�� ��û
// godbolt.org �� ������ ������
template int	square<int>(int a);
template double square<>(double a);
template float	square(float a);

int main()
{

}

