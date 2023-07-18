#include <type_traits> // std::type_identity 가 이헤더 필요!

// 아래 함수 템플릿은 반드시 타입을 명시적으로 보내야 합니다.
template<typename T>
void foo(typename std::type_identity<T>::type)
{
}
// 아래 2개를 비교해 봅시다
template<typename T> 
void f1(T a, T b)
{
}
template<typename T>
void f2(T a, typename std::type_identity<T>::type b)
{
}
int main()
{
//	foo(3); // error
	f1(3, 3.3);
	f2(3, 3.3);
}