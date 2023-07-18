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
	
	f1(3, 3.3); // error. 타입 인자가 생략되었으므로
				// 함수 인자로 타입을 추론해야 하는데.
				// 1번째 인자로 추론하면 : T=int
				// 2번째 인자로 추론하면 : T=double
				// 따라서, 컴파일러는 타입 추론 못합니다. error

	f2(3, 3.3); // 1번째 인자로 T=int 로 추론
				// 2번째 인자는 "std::type_identity<int>::type" 이므로
				// f2(int, int) 인데. 3.3 은 int로 전달 가능

				// 즉, f2는 2번째 인자의 타입의 조건은
				// 1번째 인자로 변환가능한 타입이면 ok.!
}