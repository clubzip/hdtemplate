#include <iostream>
#include <string>

class Animal {};
class Dog : public Animal {};

template<typename T> class smart_ptr
{
	T* obj = nullptr;
public:
	explicit smart_ptr(T* p) : obj(p) {}

	// �����Ҷ� "�Ʒ� �ڵ� �������ؼ� ���� �޼��� ������"
	// => ���ø����� �Լ� �����Ŀ� ": obj(sp.obj)" ������ �߻��� ����!
	// Generic  constructor
	template<typename U>
	smart_ptr(const smart_ptr<U>& sp) : obj(sp.obj) {}

	template<typename> friend class smart_ptr;
};

int main()
{
	smart_ptr<Dog>    p1(new Dog);
	smart_ptr<Animal> p2 = p1;	// ok. Dog* => Animal* �� ����(��ȯ)�����մϴ�.

	smart_ptr<int> p3 = p1;		// error. Dog* => int* �� ���� �ɼ� �����ϴ�.						   
}


