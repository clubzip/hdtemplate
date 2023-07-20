#include <iostream>
#include <type_traits>

// 현재 C++은 "특정 타입" 에 따른 함수 오버로딩을
// 지원 합니다.
void foo(int)    {}
void foo(double) {}


// "타입"이 아닌 "특정 조건을 만족하는 타입들"에 따른 오버로딩은 있으면
// 좋지 않을까요 ?
// void goo(가상함수가있는클래스들) {}
// void goo(가상함수가없는클래스들) {}

// 꼭 외우세요 : std::enable_if_t< 조건, 반환 타입>

// std::is_polymorphic_v<T> : T에 가상함수가 있으면 true, 없으면 false

template<typename T>
std::enable_if_t< std::is_polymorphic_v<T>, void >
goo(T a)
{
	std::cout << "가상함수가 있는 타입" << std::endl;
}
template<typename T>
std::enable_if_t< !std::is_polymorphic_v<T>, void >
goo(T a)
{
	std::cout << "가상함수가 없는 타입" << std::endl;
}

class AAA { public: virtual void foo() {} };

int main()
{
	AAA a;
	int n;
	goo(a); // a는 가상함수를 가진 타입
	goo(n); // n은 가상함수가 없는 타입
}
