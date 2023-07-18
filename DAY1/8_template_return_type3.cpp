#include <iostream>

// 방법 3. 2개의 인자를 서로 다른 타입이 되도록

template<typename T1, typename T2>
? add(const T1& a, const T2& b)
{
	return a + b;
}

int main()
{
	std::cout << add(3, 4) << std::endl;

	std::cout << add(3.1, 4.3) << std::endl;

	std::cout << add(3, 4.3) << std::endl;
	
}



