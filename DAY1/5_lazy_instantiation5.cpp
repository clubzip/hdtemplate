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

template<typename T>
struct Object
{
	instance_member m1;
	static static_member m2;
};
template<typename T> static_member Object<T>::m2; // 이 문법은 내일 배웁니다.

// 이제 m2 를 접근하는 코드가 없다면
// => m2의 생성자가 호출될까요 ?
int main()
{
	std::cout << "--------" << std::endl;
	Object<int> obj1;
	Object<int> obj2;
	std::cout << "--------" << std::endl;

	obj1.m2; // 이코드가 있어야 m2의 생성자가 호출됩니다.
}

// (콜백)함수 라이브러리가 템플릿으로 정의되려면 명시적 인스턴스화를 해줘야 하나요?
// => template 자체는 미리 빌드 될수 없습니다.
// => template 자체는 소스로만 배포되어야 합니다.
// => 미리 빌드하려면 명시적 인스턴스화가 필요 합니다. 
//    하지만 이경우, 사용자가 타입을 지정하기 어렵습니다.(템플릿의 의미가 약해짐)
// => STL 은 대부분(80% 이상) 소스로만 제공됩니다.

