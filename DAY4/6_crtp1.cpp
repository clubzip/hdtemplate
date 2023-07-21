#include <iostream>

// CRTP : Curiously Recurring Template Pattern
// => 기반 클래스가 템플릿 인자로 파생 클래스의 이름을 전달 받아서
//    다양하게 활용하는 기술
// => template 을 사용한 기법중.. 아주 널리 사용되는 기술.

template<typename T>
class Base
{
public:
	void fn()
	{
		// 여기서 파생 클래스의 이름을 알수 있을까 ?
		// => 미래에 만들어질 자식의 이름을 알고 싶다는 의미.!
		T obj; // Derived obj, 즉, 파생 클래스 객체를 만든것

		std::cout << typeid(obj).name() << std::endl; // Derived 
	}
};

// 파생 클래스 만들때, 기반 클래스의 템플릿 인자로
// => 자신(파생클래스)의 이름을 전달.!
class Derived : public Base< Derived >
{

};

int main()
{
	Derived  d;
	d.fn();
}





