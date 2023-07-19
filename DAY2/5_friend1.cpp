#include <iostream>

// 77 page
class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}

	friend std::ostream& operator<<(std::ostream& os, const Point& pt);
};

std::ostream& operator<<(std::ostream& os, const Point& pt)
{
	std::cout << pt.x << ", " << pt.y << std::endl;
	return os;
}

int main()
{
	Point p(1,2);

	// �ٽ� : ����� ���� Ÿ�� Point �� cout ���� ��� �Ϸ��� operator<< �� ����� �˴ϴ�.
	std::cout << p; // operator<<(cout, p)
}
