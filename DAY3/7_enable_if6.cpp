#include <iostream>
#include <string>

class Animal {};
class Dog : public Animal {};

template<typename T> class smart_ptr
{
	T* obj = nullptr;
public:
	explicit smart_ptr(T* p) : obj(p) {}

	// 복습할때 "아래 코드 컴파일해서 에러 메세지 보세요"
	// => 템플릿에서 함수 생성후에 ": obj(sp.obj)" 때문에 발생한 에러!
	// Generic  constructor
	template<typename U>
	smart_ptr(const smart_ptr<U>& sp) : obj(sp.obj) {}

	template<typename> friend class smart_ptr;
};

int main()
{
	smart_ptr<Dog>    p1(new Dog);
	smart_ptr<Animal> p2 = p1;	// ok. Dog* => Animal* 로 복사(변환)가능합니다.

	smart_ptr<int> p3 = p1;		// error. Dog* => int* 로 복사 될수 없습니다.						   
}


