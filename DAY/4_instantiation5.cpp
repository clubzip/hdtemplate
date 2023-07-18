#include <tuple>

// convenient function template
// => Ŭ���� ���ø��� ���� ���� Ÿ������ ������ ������ ���Դϴ�.
// => �̷���쿡�� �Լ� ���ø��� �����ϸ� ���ϰ� ����Ҽ� �ֽ��ϴ�.

template<typename T1, typename T2, typename T3>
std::tuple<T1, T2, T3> 
make_tuple(T1 a, T2 b, T3 c)
{
	return std::tuple<T1, T2, T3>(a, b, c);
}
int main()
{
	// C++17  �������� tuple ���� �ݵ�� Ÿ�� �����ؾ� �߽��ϴ�.
	std::tuple<int, double, char> t1(10, 3.3, 'A');

	// �ٽ� : make_tuple �� ���ø� ������
	//       �Լ� ���ø��̹Ƿ� Ÿ�� ���������մϴ�.
	//auto t2 = make_tuple(10, 3.3, 'A');
	auto t2 = std::make_tuple(10, 3.3, 'A');

	// ��, C++17 ���ʹ� make_tuple ������� �ʾƵ�
	// Ŭ���� ���ø� ��ü�� Ÿ�� ������ �����մϴ�.
	std::tuple t3(10, 3.3, 'A');
			
}