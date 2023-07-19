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

// 아래 처럼 만들면 Point<int> 타입만 cout 으로 출력가능합니다.
/*
std::ostream& operator<<(std::ostream& os, const Point<int>& pt)
{
	std::cout << pt.x << ", " << pt.y << std::endl;
	return os;
}
*/
// Point<int> 뿐 아니라 Point<double> 등도 가능하게 하려면 template 으로 해야 합니다
// => 그런데.. 왜!!!! main 에서 에러가 나올까요 ?? 원인이 뭘까요? 어려운 문제 입니다.!
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
