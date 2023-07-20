#include <iostream>

// is_pointer, is_array �� �̹� ǥ�ؿ� ��� �����˴ϴ�.- C++11 ����
#include <type_traits>


template<typename T>
void fn(T& arg)
{
	// �迭���� �����ϴ� ���
	bool b = std::is_array<T>::value;

	// �迭�� ũ�⸦ �����ϴ� ����� �츮�� �տ��� ����Ͱ��� �ٸ��ϴ�.
	// (ǥ���� 1��, 2��, 3��.. �� ��� ũ�⸦ ���Ҽ� �ֽ��ϴ�.
	int n1 = std::extent<T, 0>::value;
	int n2 = std::extent<T, 1>::value;

	printf("%d, %d, %d\n", b, n1, n2);
}
int main()
{
	int x[3][2];
	fn(x);
}
