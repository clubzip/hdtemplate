#include <iostream>

// 77 page

template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}

	friend std::ostream& operator<<(std::ostream& os, const Point& pt);
};

// �Ʒ� ó�� ����� Point<int> Ÿ�Ը� cout ���� ��°����մϴ�.
/*
std::ostream& operator<<(std::ostream& os, const Point<int>& pt)
{
	std::cout << pt.x << ", " << pt.y << std::endl;
	return os;
}
*/
// Point<int> �� �ƴ϶� Point<double> � �����ϰ� �Ϸ��� template ���� �ؾ� �մϴ�
// => �׷���.. ��!!!! main ���� ������ ���ñ�� ?? ������ �����? ����� ���� �Դϴ�.!
template<typename T>
std::ostream& operator<<(std::ostream& os, const Point<T>& pt)
{
	std::cout << pt.x << ", " << pt.y << std::endl;
	return os;
}


int main()
{
	Point<int> p(1, 2);

	std::cout << p; 
}
