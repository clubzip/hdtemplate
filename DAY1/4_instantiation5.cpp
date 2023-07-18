#include <tuple>

// convenient function template
// => 클래스 템플릿을 직접 사용시 타입인자 때문에 복잡해 보입니다.
// => 이런경우에는 함수 템플릿을 도입하면 편리하게 사용할수 있습니다.

template<typename T1, typename T2, typename T3>
std::tuple<T1, T2, T3> 
make_tuple(T1 a, T2 b, T3 c)
{
	return std::tuple<T1, T2, T3>(a, b, c);
}
int main()
{
	// C++17  이전에는 tuple 사용시 반드시 타입 전달해야 했습니다.
	std::tuple<int, double, char> t1(10, 3.3, 'A');

	// 핵심 : make_tuple 도 템플릿 이지만
	//       함수 템플릿이므로 타입 생략가능합니다.
	//auto t2 = make_tuple(10, 3.3, 'A');
	auto t2 = std::make_tuple(10, 3.3, 'A');

	// 단, C++17 부터는 make_tuple 사용하지 않아도
	// 클래스 템플릿 자체에 타입 생략이 가능합니다.
	std::tuple t3(10, 3.3, 'A');
			
}