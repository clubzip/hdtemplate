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

	// 핵심 : 사용자 정의 타입 Point 를 cout 으로 출력 하려면 operator<< 를 만들면 됩니다.
	std::cout << p; // operator<<(cout, p)
}
