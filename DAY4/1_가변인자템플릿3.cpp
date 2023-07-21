#include <iostream>

int hoo(int a) { return -a; }

void goo(int a, int b, int c) 
{
	printf("goo : %d, %d, %d\n", a, b, c);
}

template<typename ... Types> 
void foo(Types ... args)
{
	// 핵심 1. parameter pack 이라는 용어 알아 두세요
	// foo(1,2,3) 으로 사용했다면
	// Types : int, int, int   => "template parameter pack" 이라고합니다
	// args  : 1, 2, 3         => "function parameter pack" 이라고합니다

	// 핵심 2. pack 에 있는 갯수를 구하는 방법 
	std::cout << sizeof...(Types) << std::endl; // 3
	std::cout << sizeof...(args)  << std::endl; // 3

	// 핵심 3. pack expansion
	// => pack 에 있는 모든 요소를 , 를 사용해서 열거해달라는 의미
	// => args... : E1, E2, E3
	// 
	// => "pack을 사용하는 패턴"...   => "E1패턴", "E2패턴", "E3패턴"

//	goo( args ); // error. pack 의 이름을 직접 함수 인자로 사용할수 없습니다.

	goo(args...); // ok.. goo(1, 2, 3)

	goo((++args)...); // ok. goo(++E1, ++E2, ++E3) => goo(2, 3, 4)

//	goo(hoo(args...));  // goo( hoo( E1, E2, E3 ) ) 으로 코드가 생성되는데..
						// => hoo() 의 인자는 한개 이므로 error.

	goo(hoo(args)...);	// goo( hoo( E1), hoo(E2), hoo(E3) ) 
}





int main()
{
	foo(1, 2, 3);
}
