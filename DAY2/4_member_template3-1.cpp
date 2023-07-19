// coercion by member template

#include <string>
#include <type_traits>

template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}

	
	// �Ʒ� �ڵ� ���� ���� �޼�����
	/*
	template<typename U>
	Point(const Point<U>& p) : x(p.x), y(p.y) {}
	*/

	// �Ʒ� �ڵ� ������ ���� �޼����� ���� ������
	// U => V �� ���� �ɼ� ���ٸ� ���ø� ��ü�� ������� ���ϰ� �ϴ� ��� - ���Ϲ��ϴ�.
	template<typename U, 
			 typename = std::enable_if_t<std::is_convertible_v<U, T>> > 

	Point(const Point<U>& p) : x(p.x), y(p.y) {}


	template<typename> friend class Point;
};


int main()
{
	Point<int> p1(1, 2);	
	Point<double> p2 = p1; // int �� double �� ���� �����ϹǷ� ok..

	Point<std::string> p3("1", "2");
	Point<int> p4 = p3;		// U = std::string,  T = int �ε�
							// std::string -> int �� ���� �ɼ� �����Ƿ� ����
}
