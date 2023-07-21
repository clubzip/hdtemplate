#include <iostream>

// f1, f2 에 중요한 알고리즘을 작성했는데..
// => 성능이 중요합니다.!
void f1(int n) {}
void f2(int n, double d) {}

// 함수의 수행시간을 측정하는 함수를 만들어 봅시다.
// => 아래 처럼 만들면 인자가 한개인 함수만 사용가능 합니다.
template<typename F, typename ARG>
void chronometry(F f, ARG arg)
{
	// ========= 시간 기록
	f(arg);   // 함수 호출
	// ========= 수행 시간 출력
}

int main()
{
	chronometry(f1, 10); // f1(10) 의 수행시간을 측정해 달라는 것
}
