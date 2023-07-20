#include <iostream>
#include <type_traits>

// 조건에 따라 다른 함수를 호출하는 방법
// 1. if 조건문 사용 : 실행시간에 조건 조사후 함수 호출이 결정됨..
//					  if (false) 인 경우의 함수 템플릿도.. 인스턴스화 됨..
// 
// 2. 함수 오버로딩  : 컴파일 시간에 함수 호출이 결정됨..
//					  사용되지 않은 함수 템플릿은 인스턴스화에 포함 안됨 	

template<typename T> void f(T, int) {}    // A
template<typename T> void f(T, double) {} // B

f(value, 3.3);	// B 사용..
				// A는 사용된 적이 없으므로 인스턴스화에 포함 안됨.

if (false)
	f(value, 1);	// 이 경우는 실행되지 않지만, 인스턴스화에 포함됨
else 
	f(value, 3.3);








template<typename T>
void printv_pointer(const T& value)
{
	std::cout << "pointer version : " << value << " : " << *value << std::endl;
}

template<typename T>
void printv_not_pointer(const T& value)
{
	std::cout << "not pointer version : " << value << std::endl;
}



template<typename T>
void printv(const T& value)
{
	if (std::is_pointer_v<T>)		
		printv_pointer(value);		
	else
		printv_not_pointer(value);
}


int main()
{
	int n = 10;
	printv(&n);
	printv(n);

}


