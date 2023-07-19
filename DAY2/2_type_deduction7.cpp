// 2번 복사해오세요
#include <iostream>
#include "fname.h"

// 핵심 : template 과 배열 인자

template<typename T>
void f1(T a, T b)
{
	std::cout << _FNAME_ << std::endl;
}
template<typename T>
void f2(T& a, T& b)
{
	std::cout << _FNAME_ << std::endl;
}

int main()
{
	// 문자열 리터럴의 타입은 ?  =>  const char[]
	// "orange" : const char[7]
	// "apple"  : const char[6]
	// 즉, "orange" 와 "apple" 는 다른 타입 입니다.

	f1("orange", "apple");	// f1 은 인자를 T로 받게 됩니다.
							// => 이경우, 배열을 보내면 포인터로 받게 됩니다.
							// => const char[7] => const char*
							// => const char[6] => const char*
							// => 2개의 인자가 같은 타입이므로 "에러아닙니다."

	f2("orange", "apple");	// f2 는 T& 이므로 "포인터가 아닌 배열 자체로" 받게 됩니다.
							// "orange", "apple" 은 다른 타입입니다.
							// f2는 같은 타입을 요구하므로 error

	f2("orange", "banana"); // ok.. 글자 갯수가 동일하므로 같은 타입 입니다.
}
// 결론 : 함수 템플릿에 문자열 2개를 전달할때
// => T& 로 받으면 "문자열의 길이가 다르면 다른 타입" 으로 해석됩니다.
// => T 로 받으면 "같은 타입" 입니다.

// 배열이 포인터로 변경되어서 전달되는 것을 "decay" 라고 합니다.

// 매개변수에 포인터 대신 레퍼런스를 이용해 배열을 전달하는 것은 방어적으로 
// 코드를 짜기 위한 방법중 하나라고 보면 될까요?
// 포인터로 받으면 : 크기 정보를 잃어 버리게 됩니다. 별도로 크기 전달해야 합니다.
// 참조로 받으면 : 크기 정보가 포함됩니다. 별도로 크기 전달할 필요 없습니다.
//						=> 오후 수업 참고