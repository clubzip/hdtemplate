#include <iostream>

// (args + ...)	    // E1+(E2+(E3+(E4+E5)))		 unary  right fold
// (args + ... + 0) // E1+(E2+(E3+(E4+(E5+0))))  binary right fold

// (... + args)	    // (((E1+E2)+E3)+E4)+E5		 unary  left fold
// (0 + ... + args) // ((((0+E1)+E2)+E3)+E4)+E5  binary left fold


template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}

template<typename ... Types>
void show(Types... args)
{
	// args 의 모든 요소를 출력하고 싶다.
	// 핵심 1. 초기값 위치에는 0 같은 "값" 뿐아니라 "객체" 가 와도 됩니다.
//	(std::cout << ... << args); // fold expression 입니다
								// 어떻게 코드가 생성될지 생각해 보세요
							    // ( 0 + ... + args) 의 모양입니다.
	// ((((cout << E1) << E2) << E3) << E4) << E5

	// 핵심 2. pack 위치에는 "pack이름" 뿐 아니라
	//         "pack 을 사용하는 패턴"이 와도 됩니다.

	(printv(args), ...); // (args + ...) 의 모양입니다. 
						 // args 대신 printv(args)
						 // +    대신 , 연산자

	// printv(E1), ( printv(E2) , (printv(E3) , (printv(E4)))))
}


int main()
{
	show(1, 2, 3, 4, 5);
}
