#include <iostream>

// is_pointer, is_array 는 이미 표준에 모두 제공됩니다.- C++11 부터
#include <type_traits>


template<typename T>
void fn(T& arg)
{
	// 배열인지 조사하는 방법
	bool b = std::is_array<T>::value;

	// 배열의 크기를 조사하는 방법은 우리가 앞에서 만든것과는 다릅니다.
	// (표준은 1차, 2차, 3차.. 의 모든 크기를 구할수 있습니다.
	int n1 = std::extent<T, 0>::value;
	int n2 = std::extent<T, 1>::value;

	printf("%d, %d, %d\n", b, n1, n2);
}
int main()
{
	int x[3][2];
	fn(x);
}
