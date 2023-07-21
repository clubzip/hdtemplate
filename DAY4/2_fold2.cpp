#include <iostream>

// fold expression
// => () 가 반드시 있어야 합니다.
// => 4개 종류가 있습니다.
// => '+' 위치에 어떠한 이항 연산자도 올수 있습니다.
// => '0' 위치에 어떠한 값(변수)도 올수 있습니다(init value 라고 합니다.)

// 핵심 : pack 의 위치에 따라 () 의 위치가 달라 집니다.
// ===> pack 이 왼쪽
// (args + ...)	    // E1+(E2+(E3+(E4+E5)))		 unary  right fold
// (args + ... + 0) // E1+(E2+(E3+(E4+(E5+0))))  binary right fold

// ===> pack 이 오른쪽
// (... + args)	    // (((E1+E2)+E3)+E4)+E5		 unary  left fold
// (0 + ... + args) // ((((0+E1)+E2)+E3)+E4)+E5  binary left fold


template<typename ... Types>
auto sum(Types... args)
{
	return (args + ... + 0); 
			// 1+(2+(3+(4+(5+0)))) 
}

int main()
{
	auto ret = sum(1, 2, 3, 4, 5);

	std::cout << ret << std::endl;
}
