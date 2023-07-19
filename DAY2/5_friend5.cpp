#include <iostream>

// 77 page

template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}

//	friend std::ostream& operator<<(std::ostream& os, const Point<T>& pt);

	// 해결책 1. 위 처럼 "friend 일반 함수" 로 하지 말고
	//		            "friend 함수 템플릿" 으로 하세요
	// => 최선의 코드는 아닙니다. 
	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const Point<U>& pt);
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

	std::cout << p; 
}
