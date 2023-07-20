#include <iostream>

// 변수의 선언에서 변수 이름을 제외하면 타입만 남게 됩니다.

//int n;		// 변수이름 : n,    변수 타입 : int

//double d;   // 변수이름 : d,    변수 타입 : double

//int x[3];	// 변수이름 : x     x의 타입 : int[3]		
			//							  T[N] : 

// T[N] : 임의 타입의 임의 크기를 가지는 배열
// T[]  : unknown-size array 라는 특별한 타입입니다.






// is_pointer 구현을 참고해서 is_array 만들어 보세요


template<typename T> struct is_array
{
	static constexpr int size = -1;
	static constexpr bool value = false;
};
// primary template 의 템플릿 인자가 한개라도
// 부분 특수화 버전에서는 인자의 갯수는 변경될수 있다!!
// 어제 예제 : Object<T, Object<U, V>>
template<typename T, int N> struct is_array<T[N]>
{
	static constexpr int size = N;
	static constexpr bool value = true;
};

template<typename T> 
void fn(T& arg)
{	
	// T : int[3]
	if ( is_array<T>::value )
		std::cout << "array, size = "  << is_array<T>::size << std::endl;
	else
		std::cout << "not array" << std::endl;
}

int main()
{
	int n = 0;
	int x[3] = {1,2,3};

	fn(n);	// 0(false)
	fn(x);	// 1(true) 나와야 합니다.
	
}
