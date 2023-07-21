#include <iostream>

// fold expression ( C++17 )
// => parameter pack 안에 모든 요소에 대해서 이항 연산을 수행하는 표현식

template<typename ... Types>
auto sum(Types... args)
{
	// args 안의 모든 요소에 대해 합을 구하고 싶다.	
	// args    : 1 , 2 , 3 , 4 , 5 , 2.4 , 4.3
	// 원하는것 : 1 + 2 + 3 + 4 + 5 + 2.4 + 4.3
	// => pack 안의 모든 요소에 대해 "이항연산(+)"를 해야 합니다.
	// => C++17의 fold expression 을 사용하면 됩니다

//	auto ret = (args + ...); // pack(args) 의 모든 요소에 + 수행
							 // args 에 요소가 없으면 error

	auto ret = (args + ... + 0); // E1 + E2 + E3 후에 "+ 0" 도 추가
								 // args에 요소가 없어도 ok
	return ret;
}

int main()
{
//	auto ret = sum(1, 2, 3, 4, 5, 2.4, 4.3);
	auto ret = sum();

	std::cout << ret << std::endl;
}
