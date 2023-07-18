#include <iostream>

// 방법 3-3. 반환 타입으로 auto 만 표기!

template<typename T1, typename T2>
auto add1(const T1& a, const T2& b) -> decltype(a + b) 
{
	return a + b;
}

// auto 만 표기해도 됩니다.
template<typename T1, typename T2>
auto add2(const T1& a, const T2& b)
{
	if (a == 1) return a;
	
	return a + b;
}

// add1 vs add2
// add1 : 반환 타입을 사용자가 지정 한것 "decltype(a+b)"로 해달라고!
//			=> return 문장이 여러개 있어도 가능
// 
// add2 : 반환 타입을 컴파일러가 return 문장을 보고 추론해 달라는 것
//			=> return 문장이 한개일때만 가능
//			=> return 문장이 여러개 있다면 error

// add1, add2 는 또다른 차이가 있습니다 - 내일

int main()
{
	std::cout << add2(3, 4) << std::endl;
	std::cout << add2(3.1, 4.3) << std::endl;
	std::cout << add2(3, 4.3) << std::endl;


}



