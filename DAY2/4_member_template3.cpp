// coercion by member template

template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}



	// 1. 복사 생성자를 생각해 봅시다.
//	Point(const Point& pt) : x(pt.x), y(pt.y) {}    // 이코드는 
//	Point(const Point<T>& pt) : x(pt.x), y(pt.y) {} // 이 코드와 동일

				// => Point<double> p3 = p1  의 코드에서
				// => p1은 반드시 Point<double> 이어야만 합니다.
				// => p1 이 Point<int> 라면 에러!
				// => 즉, 복사 생성자는 자신과 동일한 타입만 받을수 있습니다.

	// 2. 인자가 Point<int> 인 생성자를 생각해 봅시다.
//	Point(const Point<int>& p) {}
		// => Point<double> p3 = p1 일때 
		// => p1이 Point<int> 라면 에러 아닙니다.
		// => p1이 Point<short> 라면 에러 입니다.


	// 3. Generic 생성자 (또는 Generic 복사 생성자 라고도 합니다)
	// U(int)가 T(double)로 복사(대입 될수 있다면)
	// Point<U> 는 Point<T> 로 복사(대입) 될수 있어야 한다.
	// => Generic 생성자 가 필요 
	template<typename U>
	Point(const Point<U>& p) {}
};







int main()
{
	Point<int> p1(1, 2);	// ok.. 인자가 2개인 생성자

	Point<int> p2 = p1;		// ok.. 컴파일러가 제공한 복사 생성자 사용

	// p1, p3 는 다른 타입입니다..
	// 복사 생성자는 같은 타입일때 호출되는 생성자!!
	Point<double> p3 = p1; // ?
}
