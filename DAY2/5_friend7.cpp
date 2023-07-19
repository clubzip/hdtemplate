#include <iostream>

// 77 page

template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}

	// friend5.cpp   : N : N �� friend ���� �ڵ� �Դϴ�
	// �Ʒ� ó�� �ϸ� : 1 : 1 �� friend ���� �Դϴ�. - �� �ڵ尡 �����Դϴ�.!!
	friend std::ostream& operator<<(std::ostream& os, const Point<T>& pt)
	{
		std::cout << pt.x << ", " << pt.y << std::endl;
		return os;
	}
};



int main()
{
	Point<int>    p1(1, 2); // <==> operator<<( Point<int> )

	Point<double> p2(1, 2); // <==> operator<<( Point<double> ) �� friend ��˴ϴ�.
							// ��, N:N �� friend �� �ƴ� 1:1 �� friend �� �˴ϴ�.


	std::cout << p1;
}
