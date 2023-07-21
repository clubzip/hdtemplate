#include <iostream>

int hoo(int a) { return -a; }

void goo(int a, int b, int c) 
{
	printf("goo : %d, %d, %d\n", a, b, c);
}

template<typename ... Types> 
void foo(Types ... args)
{
	// �ٽ� 1. parameter pack �̶�� ��� �˾� �μ���
	// foo(1,2,3) ���� ����ߴٸ�
	// Types : int, int, int   => "template parameter pack" �̶���մϴ�
	// args  : 1, 2, 3         => "function parameter pack" �̶���մϴ�

	// �ٽ� 2. pack �� �ִ� ������ ���ϴ� ��� 
	std::cout << sizeof...(Types) << std::endl; // 3
	std::cout << sizeof...(args)  << std::endl; // 3

	// �ٽ� 3. pack expansion
	// => pack �� �ִ� ��� ��Ҹ� , �� ����ؼ� �����ش޶�� �ǹ�
	// => args... : E1, E2, E3
	// 
	// => "pack�� ����ϴ� ����"...   => "E1����", "E2����", "E3����"

//	goo( args ); // error. pack �� �̸��� ���� �Լ� ���ڷ� ����Ҽ� �����ϴ�.

	goo(args...); // ok.. goo(1, 2, 3)

	goo((++args)...); // ok. goo(++E1, ++E2, ++E3) => goo(2, 3, 4)

//	goo(hoo(args...));  // goo( hoo( E1, E2, E3 ) ) ���� �ڵ尡 �����Ǵµ�..
						// => hoo() �� ���ڴ� �Ѱ� �̹Ƿ� error.

	goo(hoo(args)...);	// goo( hoo( E1), hoo(E2), hoo(E3) ) 
}





int main()
{
	foo(1, 2, 3);
}
