#include <iostream>
#include <type_traits>

// 방법 2. std::type_identity 사용 - C++20 안되시면 앞에서(인스턴스화8번)
//								만든것 복사해 오세요
// => 1번째 인자로만 타입을 결정하겠다는 의도
// => 2번째 인자의 타입은 1번째 인자 타입으로 변환가능하면 ok
template<typename T>
T add(const T& a, const typename std::type_identity<T>::type & b)
{
	return a + b;
}

int main()
{
	std::cout << add(3, 4) << std::endl;
	std::cout << add(3.1, 4.3) << std::endl;

	std::cout << add(3, 4.3) << std::endl; // ok
									// 단, add(int, int) 로 결정
									// 따라서 결과는 7

	std::cout << add<double>(3, 4.3) << std::endl;
}



