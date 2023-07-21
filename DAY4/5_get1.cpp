#include <iostream>

struct Base
{
	int value = 10;
};
struct Derived : public Base
{
	// 기반 클래스와 동일이름의 멤버 데이타를 추가해도 됩니다.
	int value = 20;
};
int main()
{
	Derived d;

	std::cout << d.value << std::endl; // 20
	std::cout << static_cast<Base&>(d).value << std::endl; // 10
}
