#include <iostream>

// 핵심 
// template : 컴파일 시간에 컴파일러에 의한 코드 생성
// => 따라서, 모든 템플릿 인자는 "컴파일 시간에 값을 알아야" 합니다.

template<typename T, int N> 
struct Object
{
	// 템플릿 인자 N 은 컴파일 시간에 값을 알수 있으므로
	// 배열 크기로 사용가능합니다.
	T buff[N];	 // ok.. 
};
int main()
{
	Object<int, 10> obj1;	// ok. 10 은 컴파일러가 알수 있는 값..!

	int n = 10;
	Object<int,  n> obj2;	// error. n은 변수이므로 컴파일 할때 값을 알수 없습니다.
				
	const int c1 = 10;	// c1 은 컴파일 시간에 초기값을 알수 있습니다
	const int c2 = n;	// c2 의 초기값은 컴파일 시간에 알수 없습니다.

	Object<int, c1> obj3; // ok.
	Object<int, c2> obj4; // error. 

	// constexpr 은 항상 컴파일 시간에 초기값을 알수 있으므로 템플릿 인자로 항상 사용가능
	constexpr int c3 = 10; // ok
	constexpr int c4 = n;  // error.
}


