#include <iostream>
#include <type_traits>

// 조건을 만족하지 않을때 인스턴스화에서 제외하는 기술은 
// 대표적으로 4가지가 있습니다. ( 모두 C++ 표준에서 지원 )

// 1. std::integral_constant - C++11 기술, 가장 이해하기 어렵습니다.
// 2. std::enable_if         - C++11 기술, C++20 이전에 가장 널리 사용했던 기술
// 3. if constexpr           - C++17 기술, 가장 간단한 방법
// 4. requires clauses       - C++20 기술, 가장 발전된 형태의 기술..
// 
// 결국, 미래에는 3번, 4번을 사용하게 됩니다.!!! 							        



// cppinsights.io 에서 아래 코드 붙여넣기 하세요
template<typename T>
void printv(const T& value)
{
	if constexpr (std::is_pointer_v<T>)
		std::cout << value << " : " << *value << std::endl;
	else
		std::cout << value << std::endl;
}

int main()
{
	int n = 10;
	printv(&n);
	printv(n);

}


