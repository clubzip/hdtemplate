#include <iostream>
#include <type_traits>
class String
{
public:
	String(const char* s) {}
	String(const String& s) { std::cout << "copy ctor" << std::endl; }
	String(String&& s) { std::cout << "move ctor" << std::endl; }
};
/*
// 타입 추론을 생각해 보세요
// "T&& obj = 함수인자" 에서
//								T			T&&
// 함수인자가 lvalue(s1)		 :	String&	    String& && => String&
// 함수인자가 rvalue(임시객체) :  String		String&&

template<typename T>
T&& move(T&& obj)
{
	return static_cast<T&&>(obj);
}
*/

template<typename T>
constexpr std::remove_reference_t<T>&& move(T&& obj) noexcept
{
	// static_cast<T&&>(obj) : T가 참조를 포함했다면 rvalue 캐스팅이 아닌
	//						   lvalue 캐스팅이 될수도 있습니다.
	
	// 아래 처럼 하면
	// 1. T가 가진 모든 reference 를 먼저 제거하고
	// 2. 다시 && 를 붙여서 캐스팅하므로
	// 3. rvalue 캐스팅임을 보장할수 있습니다.
	return static_cast<std::remove_reference_t<T> &&>(obj);
}

int main()
{
	String s1 = "hello";
	String s2 = s1;			
	String s3 = move(s1);	
	String s4 = move(String("hello"));
}