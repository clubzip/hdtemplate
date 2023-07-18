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
// �ٽ� 1. static ��� ����Ÿ�� Object ��ü�� �������� �ʾƵ�
//       �޸𸮿� ���̰� �˴ϴ�.
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
// �ᱹ, instance ����� m1�� �����ڴ� ��ü�� �ѹ��� ȣ�������
//      static ����� m2�� �����ڴ� Object Ŭ������ ���ؼ��� 1��ȣ��˴ϴ�.
// => ��, ��ü�� �ƴ� Ŭ������ �ѹ� �Դϴ�.

