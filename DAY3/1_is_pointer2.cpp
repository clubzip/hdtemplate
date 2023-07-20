#include <iostream>

// type traits 
// => 타입에 대한 다양한 특성(특질)을 조사하는 기술
// => 컴파일 시간에 사용하는 함수(메타 함수)로 생각할수 있습니다.
// => 만드는 법
// 1. primary template 을 만들고 false 리턴(value=false라는 의미)
// 2. 조건을 만족하는 부분 특수화 버전을 만들고 true 리턴 (value = true )


// 아래 코드가 T 가 포인터 인지 조사하는 기술 입니다.

template<typename T> struct is_pointer
{
	// 아래 처럼 만들면
//	bool value = false;  // 1. 컴파일 시간 상수가 아닌 변수가 됩니다.
						 // 2. C++11 이전에는 구조체 멤버에서직접 =로 초기화 할수 없습니다

	// C++11 이전에
	// => 구조체 안에서 직접 초기화 하고
	// => 컴파일 시간에 사용가능한 상수를 만드는 유일한 방법은 "enum" 밖에 없었습니다.
	// => "enum hack" 이라고 불리던 기술입니다.
//	enum { value = false }; 

	// C++11 이후에는 위처럼 enum 사용하지 않고, 아래 처럼 만들고 있습니다.
	static constexpr bool value = false;
};

template<typename T> struct is_pointer<T*>
{
//	enum { value = true };
	static constexpr bool value = true;
};


template<typename T> 
void fn(const T& arg)
{
	// 현재 T는 int, int* 
	if (  is_pointer<T>::value  )
		std::cout << "pointer" << std::endl;
	else
		std::cout << "not pointer" << std::endl;
}


int main()
{
	int n = 0;
	fn(n);
	fn(&n);
}
