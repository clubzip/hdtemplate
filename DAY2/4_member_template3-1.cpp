// coercion by member template

#include <string>

template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}

	template<typename U>
	Point(const Point<U>& p) : x(p.x), y(p.y) {}

	template<typename> friend class Point;
};


int main()
{
	Point<int> p1(1, 2);	
	Point<double> p2 = p1; 

	Point<std::string> p3("1", "2");
	Point<int> p4 = p3;
}
