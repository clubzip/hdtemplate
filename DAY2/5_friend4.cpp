#include <iostream>

// 77 page

template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}


	// Ŭ���� ���ø� �ȿ��� �Լ� ������ Point �� Point<T> �� ���� ǥ�� �Դϴ�.
	
//	friend std::ostream& operator<<(std::ostream& os, const Point& pt);
	friend std::ostream& operator<<(std::ostream& os, const Point<T>& pt);

	// "Point<int> p" ó�� �ν��Ͻ��� �����ϸ� �ᱹ �� �ڵ�� 
//	friend std::ostream& operator<<(std::ostream& os, const Point<int>& pt);

	// ���� �Ʒ� �ּ��� ������ ������
	// 1. operator<<( Point<T> ) ������ Ŭ���� �ܺο� �ֽ��ϴ�.
	// 2. operator<<( Point<int>) ������ Ŭ���� �ȿ� ���� �ֽ��ϴ�.
};
 
template<typename T>
std::ostream& operator<<(std::ostream& os, const Point<T>& pt)
{
	std::cout << pt.x << ", " << pt.y << std::endl;
	return os;
}

int main()
{
	Point<int> p(1, 2);

	std::cout << p; // �̼��� operator<<( Point<T> ) �� �ƴ�
					//       operator<<( Point<int> ) �� ã�� �˴ϴ�.(friend ���𶧹���)
					// �Լ��� ã���� ���� ������ ����!
}
