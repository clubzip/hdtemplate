#include <iostream>

// int2type : 정수형 상수를 타입으로 만드는 시스템
//			  주로 함수 오버로딩으로 활용
//			  1, 2, 3 등의 값에 따라 다른 함수를 선택하게 하는 기술
//			  2003년 modern C++ design 책의 저자인 "안드레이 알렉산드레스큐"

// C++표준위원회는 C++11 만들때 int2type 을 발전시켜서 표준에 넣었습니다.
template<int N>
struct int2type
{
	enum { value = N };
};

// int -> type 뿐 아니라, long->type, char->type 등을 모두 지원하기 위해
// 아래 처럼 만들었습니다.
template<typename T, T N>
struct integral_constant
{
	static constexpr T value = N;
};

// 아래 n1, n2, n3 는 모두 다른 타입입니다.
integral_constant<int, 0> n1;
integral_constant<int, 1> n2;
integral_constant<short, 0> n3;

// true, false 는 같은 타입이지만, b1, b2 는 다른 타입입니다.
integral_constant<bool, true> b1;
integral_constant<bool, false> b2;

// true_type, false_type 은 참거짓을 나타는 "타입"(값이 아닌) 입니다.
// => C++11 표준에 있습니다.
using true_type  = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;

// 이제 실제 표준의 is_pointer 는 아래처럼 만들게 됩니다.
template<typename T> struct is_pointer     : false_type {};
template<typename T> struct is_pointer<T*> : true_type {};