// coercion by member template

#include <string>
#include <type_traits>

template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}

	
	// 아래 코드 사용시 에러 메세지와
	/*
	template<typename U>
	Point(const Point<U>& p) : x(p.x), y(p.y) {}
	*/

	// 아래 코드 사용시의 에러 메세지를 비교해 보세요
	// U => V 로 복사 될수 없다면 템플릿 자체를 사용하지 못하게 하는 기술 - 내일배웁니다.
	template<typename U, 
			 typename = std::enable_if_t<std::is_convertible_v<U, T>> > 

	Point(const Point<U>& p) : x(p.x), y(p.y) {}


	template<typename> friend class Point;
};


int main()
{
	Point<int> p1(1, 2);	
	Point<double> p2 = p1; // int 는 double 에 복사 가능하므로 ok..

	Point<std::string> p3("1", "2");
//	Point<int> p4 = p3;		// U = std::string,  T = int 인데
							// std::string -> int 로 복사 될수 없으므로 에러
}
