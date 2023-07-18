#include <vector>

template<typename T>
T square(T a)
{
	return a * a;
}

template<typename T>
class List
{
public:
	List(int sz, const T& value) {}
};

int main()
{
	// 1. function template
	// => 타입을 명시적으로 전달해도 되고, 타입을 생략해도 됩니다.
	square<int>(3);	// ok
	square(3);		// ok

	// 2. class template
	// => C++17 부터 타입인자 생략이 가능합니다.
	List<int> s1(10, 3); // ok
	List      s2(10, 3); // error . ~ C++14
						 // ok      C++17 ~ 

	// STL 사용시, C++17 이후 부터는 타입인자 생략 가능합니다.

	std::vector<int> v1 = { 1,2,3 };
	std::vector      v2 = { 1,2,3 }; // ok. C++17 이후 부터
}

