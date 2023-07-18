#include <iostream>
#include <functional>
#include <type_traits> // std::type_identity

// 27page. identity
// => 아래 기술은 
// => 예전 부터 "identity" 라는 이름으로 사용되었습니다.
// => 그런데, C++20 에서 표준에 도입되었는데. 
//    이름이 "std::type_identity" 가 되었습니다.
template<typename T> struct type_identity
{
	using type = T;
};
// type_identity<int>::type    => int
// type_identity<double>::type => double


template<typename T> void foo(T a)
{
}

template<typename T> 
//void goo(T a)
//void goo( typename type_identity<T>::type a)
void goo(typename std::type_identity<T>::type a)
{
}
// goo<int>(3); // type_identity<int>::type 이므로 결국 goo(int a)
// goo(3);      // 3으로 인자 타입을 추론해야 하는데.
//				// type_identity 구조체 템플릿 이므로 
//				// 생성자나 deduction guide 없이는 추론 안됨.
//				// 따라서 error


int main()
{
	// 핵심 1. 함수 템플릿은 타입을 전달해도 되고 생략해도 됩니다.
	// => 생략하면 컴파일러가 함수 인자를 보고 타입을 추론합니다.
	foo(10);		// ok
	foo<int>(10);	// ok

	// 핵심 2. 컴파일러에 의한 타입 추론을 막고 싶을때가 있습니다.
	// => std::forward<T>() 가 이 기술을 사용합니다.

	goo(10);	  // error. 나오게 하고 싶다.
	goo<int>(10); // ok
}