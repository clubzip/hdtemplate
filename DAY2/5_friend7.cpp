#include <iostream>

// 77 page

template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}

	// friend5.cpp   : N : N 의 friend 관계 코드 입니다
	// 아래 처럼 하면 : 1 : 1 의 friend 관계 입니다. - 이 코드가 정답입니다.!!
	friend std::ostream& operator<<(std::ostream& os, const Point<T>& pt)
	{
		std::cout << pt.x << ", " << pt.y << std::endl;
		return os;
	}
};



int main()
{
	Point<int>    p1(1, 2); // <==> operator<<( Point<int> )

	Point<double> p2(1, 2); // <==> operator<<( Point<double> ) 만 friend 면됩니다.
							// 즉, N:N 의 friend 가 아닌 1:1 의 friend 면 됩니다.


	std::cout << p1;
}
