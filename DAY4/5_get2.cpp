#include <iostream>
#include "tuple.h"

int main()
{
//	tuple<			   char>				 // 2번째 기반, 'A'보관
//	tuple<     double, char>				 // 1번째 기반 , 3.4보관
	tuple<int, double, char> t(1, 3.4, 'A'); // t 자신은     1보관

	// 주석 처럼 결과가 나오도록 코드 수정해 보세요
	std::cout << t.value << std::endl; // 1

	std::cout << t.value << std::endl; // 3.4

	std::cout << t.value << std::endl; // 'A'
}
