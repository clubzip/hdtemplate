#include <iostream>

struct static_member
{
	static_member() { std::cout << "static_member()" << std::endl; }
	~static_member() { std::cout << "~static_member()" << std::endl; }
};
struct instance_member
{
	instance_member() { std::cout << "instance_member()" << std::endl; }
	~instance_member() { std::cout << "~instance_member()" << std::endl; }
};

//----------------------------------------------------------
// 핵심 1. static 멤버 데이타는 Object 객체를 생성하지 않아도
//       메모리에 놓이게 됩니다.
struct Object
{
	instance_member m1;
	static static_member m2;
};
static_member Object::m2;

int main()
{
	std::cout << "--------" << std::endl;
	Object obj1;
	Object obj2;
	std::cout << "--------" << std::endl;
}
// 결국, instance 멤버인 m1의 생성자는 객체당 한번씩 호출되지만
//      static 멤버인 m2의 생성자는 Object 클래스에 대해서만 1번호출됩니다.
// => 즉, 객체가 아닌 클래스당 한번 입니다.

