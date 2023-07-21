#include <iostream>
#include <tuple>

template<typename ... Types> void foo(Types ... args)
{
	// args 에 있는 모든 요소를 꺼내고 싶다면
	// 
	// args(1,2,3) 안에 있는 2번째 값을 얻고 싶다.
	// => 한번에 할수 있는 방법은 없습니다.

	// 아래 3개 방법 중에 한개를 사용해야 합니다.
	// 1. pack expansion		- C++11
	// 2. recursive 와 유사한 기술 - C++11
	// 3. fold expression - C++17

	// 방법 1. pack expansion 으로 pack 의 모든 요소를 꺼내기

	// 1.1 모든 요소의 타입이 동일하다는 확신이 있다면 배열에 담으세요
	int x[] = { args... };
			// 컴파일러는 "int x[] = { E1, E2, E3}" 로 코드를 생성합니다.
			//           "int x[] = { 1, 2, 3.4}" 였다면 결국 3.4 는 3으로 변경되어서 배열에 초기화

	// 1.2 요소의 타입이 다른 경우. tuple 에 담으세요
	std::tuple<Types...> tp(args...);
//	std::tuple           tp(args...); // C++17 부터는 이렇게도 가능

	// tuple 의 요소 접근
	std::cout << std::get<0>(tp) << std::endl;
	std::cout << std::get<1>(tp) << std::endl;
}

int main()
{
	foo(1, 2, 3);
}

