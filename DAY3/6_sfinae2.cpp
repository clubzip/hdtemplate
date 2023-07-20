#include <iostream>

// SFINAE 의 의미
// => Substitution Failure Is Not An Error
// => 치환 실패는 에러가 아니다.

// 함수 인자를 보고 템플릿을 사용하기로 결정했는데..
// => 실제 함수를 만들다가(인스턴스화) 실패하면!!
// => 컴파일 에러는 아니고, 후보에서 제외된다는 의미
// => 동일 이름의 다른 함수가 있다면 사용될수 있다는 것

template<typename T> 
typename T::type fn(T  a) { std::cout << " T "; return 0; }
//     int::type fn(int a) {...} 의 함수를 생성하려고 하는데..
//						=> int::type 은 잘못된 코드가 됩니다.
//						=> 즉, 함수 생성 실패!

int fn(... ) { std::cout << "..."; return 0; }

int main()
{
	fn(3); // T 버전을 사용하게 됩니다.
}
