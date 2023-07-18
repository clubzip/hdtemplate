#include <iostream>

template<typename T>
T square(T a)
{
	return a * a;
}

int main()
{
	// square : 함수가 아닙니다.
	//	        함수를 만들때 사용하는 틀 입니다.
	//			소스 코드로만 존재하고, 컴파일시에 사용됩니다
	//			틀 자체가 메모리에 존재하는 것은 아닙니다.
	//			틀 자체는 컴파일시만 사용하고, 기계어 코드로 변경되지도 않습니다.

//	printf("%p\n", &square);	// error. 틀의 주소를 구할수 없습니다.
//	auto p1 = &square;			// error.

	printf("%p\n", &square<int>); // ok
			// => square<int>를 호출하지는 않지만
			// => 주소를 구하는 작업 자체가 함수가 필요합니다.
			// => 따라서, 이 코드를 컴파일 할때 "인스턴스화가 되어서" 
			//	  square<int>() 함수가 생성됩니다.
}

