#include <iostream>

// �ٽ� 
// template : ������ �ð��� �����Ϸ��� ���� �ڵ� ����
// => ����, ��� ���ø� ���ڴ� "������ �ð��� ���� �˾ƾ�" �մϴ�.

template<typename T, int N> 
struct Object
{
	// ���ø� ���� N �� ������ �ð��� ���� �˼� �����Ƿ�
	// �迭 ũ��� ��밡���մϴ�.
	T buff[N];	 // ok.. 
};
int main()
{
	Object<int, 10> obj1;	// ok. 10 �� �����Ϸ��� �˼� �ִ� ��..!

	int n = 10;
	Object<int,  n> obj2;	// error. n�� �����̹Ƿ� ������ �Ҷ� ���� �˼� �����ϴ�.
				
	const int c1 = 10;	// c1 �� ������ �ð��� �ʱⰪ�� �˼� �ֽ��ϴ�
	const int c2 = n;	// c2 �� �ʱⰪ�� ������ �ð��� �˼� �����ϴ�.

	Object<int, c1> obj3; // ok.
	Object<int, c2> obj4; // error. 

	// constexpr �� �׻� ������ �ð��� �ʱⰪ�� �˼� �����Ƿ� ���ø� ���ڷ� �׻� ��밡��
	constexpr int c3 = 10; // ok
	constexpr int c4 = n;  // error.
}


