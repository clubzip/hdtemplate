#include <iostream>

// 가변 인자 함수 템플릿
// => 어떠한 형태의 함수라도 생성할수 있는 능력이 있습니다.
// => godbolt.org 에 아래 코드 복사해서 넣어 보세요
template<typename ... Types> 
void foo(Types ... args)
{

}

// 참고 : C언어의 가변인자 함수는
// => 한개의 함수가 어떠한 형태의 인자도 받을수 있는것!
void goo(const char* fmt, ...)
{
	// 한개의 함수에서.. 
	// 다양한 형태로 전달된 인자를 꺼낼수 있어야 합니다.
	// => 그래서 대 부분 호출할때 인자의 정보를 알려주어야 합니다.
	// => 인자를 꺼내는 것은 "va_list, va_arg, va_start" 등을 찾아 보세요
}
int main()
{
	foo(1);
	foo(1, 2);		  // foo(int, int) 함수 생성
	foo(1, 3.4, 'A'); // foo(int, double, char) 함수 생성
					  // Types : int, double, char
					  // args  : 1, 3.4, 'A'

	goo("%d", 1);
	goo("%d %d", 1, 2);
	goo("%d %f %c", 1, 3.4, 'A');
}
