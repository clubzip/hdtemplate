#include <iostream>
#include <vector>
#include <array>

// C++ ǥ���� std::array �� ���� ����� ���ô�.
// 1. ����ü �ȿ� �迭�� ������ main �Լ� 1��° �� ó�� �ʱ�ȭ �����մϴ�.
// => ��, ��� �����ڶ� ����� �����մϴ�.
// => = { } �� �ʱ�ȭ �����Ѱ��� aggregate type �̶�� �մϴ�.

// 2. Ÿ�԰� ���ڸ� ���ø� ���ڷ� �޾Ƽ� ����ڰ� �����Ҽ� �ְ�

// 3. �Ϲ� �迭�� �������� ������ ?
// => �پ��� ��� �Լ��� �����Ҽ� �ֽ��ϴ�.

template<typename T, std::size_t N>  // std::size_t : unsigned int
struct array
{
	T buff[N];

	std::size_t size() const { return N; }

	// STL ó�� �ݺ��� ���� ����
	using iterator = T*;

	iterator begin() { return buff; }
	iterator end()   { return buff + N; }

	T& operator[](int idx) { return buff[idx]; }
};

int main()
{
	array<int, 5> arr = { 1,2,3,4,5 };

	std::cout << arr.size() << std::endl;
	arr[0] = 10;

	auto p1 = arr.begin();
	auto p2 = arr.end();

	// vector     : ũ�� ���氡��. ��� �Լ� ����
	// std::array : ũ�� ����ȵ�. ��� �Լ� ����
	// raw array  : ũ�� ����ȵ�. ��� �Լ� ����.  <== ���� ����!!!
}
