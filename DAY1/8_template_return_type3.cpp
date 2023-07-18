#include <iostream>

// 방법 1, 2 : 2개의 인자를 같은 타입!!!
// 
// 방법 3. 2개의 인자를 서로 다른 타입이 되도록
// => 이 경우의 핵심은 "반환 타입을 어떻게 표기할것인가?" 입니다.
// => 여러가지 방법이 있습니다.
template<typename T1, typename T2>
? add(const T1 & a, const T2 & b)
{
	return a + b;
}

int main()
{
	std::cout << add(3, 4) << std::endl;

	std::cout << add(3.1, 4.3) << std::endl;

	std::cout << add(3, 4.3) << std::endl;
	
}



