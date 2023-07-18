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
	// => Ÿ���� ��������� �����ص� �ǰ�, Ÿ���� �����ص� �˴ϴ�.
	square<int>(3);	// ok
	square(3);		// ok

	// 2. class template
	// => C++17 ���� Ÿ������ ������ �����մϴ�.
	List<int> s1(10, 3); // ok
	List      s2(10, 3); // error . ~ C++14
						 // ok      C++17 ~ 

	// STL ����, C++17 ���� ���ʹ� Ÿ������ ���� �����մϴ�.

	std::vector<int> v1 = { 1,2,3 };
	std::vector      v2 = { 1,2,3 }; // ok. C++17 ���� ����
}

