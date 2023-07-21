#include <iostream>

// f1, f2 에 중요한 알고리즘을 작성했는데..
// => 성능이 중요합니다.!
void f1(int n) {}
void f2(int n, double d) {}
void f3() {}

// 아래 처럼 가변인자 템플릿으로 만들면, 인자가 어떤 형태라도
// 수행시간을 측정할수 있는 범용적인 함수를 만들수 있습니다.
// => 가변인자 템플릿을 사용하는 대표적인 스타일.. 
/*
template<typename F, typename ... ARGS>
inline void chronometry(F f, ARGS ... args)
{
	f(args...);  
}
*/

// 실제로는 이런 예제는 C++11 의 "완벽한 전달" 기술로 해야 합니다.
// => "modern C++" 과정 참고. 
template<typename F, typename ... ARGS>
inline void chronometry(F f, ARGS&& ... args)
{
	f(std::forward<ARGS>(args)...);
}

int main()
{
	chronometry(f1, 10);	// f1(10)
	chronometry(f2, 10, 20);// f2(10, 20)
	chronometry(f3 );		// f3()
}
