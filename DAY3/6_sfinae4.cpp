#include <iostream>

// SFINAE 가 적용되는 3가지 경우
// 1. 함수의 리턴 타입
// 2. 함수의 인자
// 3. 템플릿 인자
// => 즉, 함수 signature 에서만 적용됩니다.

void fn(...) { std::cout << "..." << std::endl; }

// 1. 함수의 리턴 타입을 만들때 실패하면 SFINAE 규칙 적용
// template<typename T> 
// typename T::type fn(T a) { }

// 2. 함수에 인자모양을 만들때 실패하면 SFINAE 규칙 적용
// template<typename T> 
// void fn(T a, typename T::type b = 0 ) { }
//   fn(int a,      int::type b = 0 ) {}


// 3. 템플릿 인자모양이 실패 하면 SFINAE 규칙 적용
template<typename T, 
		 typename T2 = typename T::type >
void fn(T a) { }		//    int::type 

int main()
{
	fn(3);
}
