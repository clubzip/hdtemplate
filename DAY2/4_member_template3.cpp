// coercion by member template

template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}



	// 1. ���� �����ڸ� ������ ���ô�.
//	Point(const Point& pt) : x(pt.x), y(pt.y) {}    // ���ڵ�� 
//	Point(const Point<T>& pt) : x(pt.x), y(pt.y) {} // �� �ڵ�� ����

				// => Point<double> p3 = p1  �� �ڵ忡��
				// => p1�� �ݵ�� Point<double> �̾�߸� �մϴ�.
				// => p1 �� Point<int> ��� ����!
				// => ��, ���� �����ڴ� �ڽŰ� ������ Ÿ�Ը� ������ �ֽ��ϴ�.

	// 2. ���ڰ� Point<int> �� �����ڸ� ������ ���ô�.
//	Point(const Point<int>& p) {}
		// => Point<double> p3 = p1 �϶� 
		// => p1�� Point<int> ��� ���� �ƴմϴ�.
		// => p1�� Point<short> ��� ���� �Դϴ�.


	// 3. Generic ������ (�Ǵ� Generic ���� ������ ��� �մϴ�)

	// U(int)�� T(double)�� ����(���� �ɼ� �ִٸ�)
	// Point<U> �� Point<T> �� ����(����) �ɼ� �־�� �Ѵ�.

	// => Generic ������ �� �ʿ� 
	// => "Generic ������" �� �ᱹ "class template" �� "member function template"
	template<typename U>
	Point(const Point<U>& p) : x(p.x), y(p.y) {}

	// Point<double>, Point<int> �� ���� �ٸ� Ÿ�� �̹Ƿ�
	// private ��� ������ ���ؼ� friend ���谡 �ʿ� �մϴ�.
	template<typename> friend class Point;
};







int main()
{
	Point<int> p1(1, 2);	// ok.. ���ڰ� 2���� ������

	Point<int> p2 = p1;		// ok.. �����Ϸ��� ������ ���� ������ ���

	// p1, p3 �� �ٸ� Ÿ���Դϴ�..
	// ���� �����ڴ� ���� Ÿ���϶� ȣ��Ǵ� ������!!
	Point<double> p3 = p1; // ?
}
