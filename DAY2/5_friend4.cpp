#include <iostream>

// 77 page

template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}


	// 클래스 템플릿 안에서 함수 인자의 Point 는 Point<T> 와 같은 표기 입니다.
	
//	friend std::ostream& operator<<(std::ostream& os, const Point& pt);
	friend std::ostream& operator<<(std::ostream& os, const Point<T>& pt);

	// "Point<int> p" 처럼 인스턴스를 생성하면 결국 위 코드는 
//	friend std::ostream& operator<<(std::ostream& os, const Point<int>& pt);

	// 이제 아래 주석을 생각해 보세요
	// 1. operator<<( Point<T> ) 버전이 클래스 외부에 있습니다.
	// 2. operator<<( Point<int>) 버전이 클래스 안에 선언만 있습니다.
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

	std::cout << p; // 이순간 operator<<( Point<T> ) 가 아닌
					//       operator<<( Point<int> ) 를 찾게 됩니다.(friend 선언때문에)
					// 함수를 찾을수 없기 때문에 에러!
}
