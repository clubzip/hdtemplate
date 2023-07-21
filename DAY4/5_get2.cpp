#include <iostream>
#include "tuple.h"

int main()
{
//	tuple<			   char>				 // 2번째 기반 클래스, 'A'보관
//	tuple<     double, char>				 // 1번째 기반 클래스, 3.4보관
	tuple<int, double, char> t(1, 3.4, 'A'); // t 자신은     1보관

	// 주석 처럼 결과가 나오도록 코드 수정해 보세요
	// => 아래 코드 처럼 각 요소의 접근은 결국 캐스팅(static_cast) 입니다.
	// => static_cast 는 컴파일 시간에 동작합니다.
	// => 즉, 각 요소 접근에 따른 실행시간 오버헤드는 없습니다.
	std::cout << t.value << std::endl; // 1

	std::cout << static_cast<tuple<double, char>&>(t).value << std::endl; // 3.4
	std::cout << static_cast<tuple<char>&>(t).value << std::endl; // 'A'

	// 이제 get 의 모양을 생각해 봅시다.
	double d = get<1>(t);
}

template<int N, typename TP>
튜플TP의 N번째 요소의 타입&      //  <<== 리턴타입
get(TP& tp)
{
//	return tp.value;   <<== 이렇게 하면 무조건 0번째 요소 값 반환

	return static_cast<TP의 N번째 기반클래스&>(tp).value;
}
