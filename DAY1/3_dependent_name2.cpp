// 77 page
struct Object
{
	using type = int;
	static constexpr int value = 10;

	template<typename T> struct rebind
	{
	};
};
template<typename T>
void foo(T obj)
{
	Object::value * 10; // ok.. dependent name 아님(T의존 하지 않음)
	Object::type * p1;  // ok.. dependent name 아님

	T::value * 10; // ok. dependent name, value 는 타입 아님
//	T::type* p2;   // error dependent name, type은 타입
	typename T::type* p2; // ok

	//-------------------------------
	Object::rebind<int> r1; // ok. dependant name 아님.

//	T::rebind<int> r2; // error. rebind 는 dependent name 이고
						// "타입" 이므로 typename 필요

//	typename T::rebind<int> r2; // error.
								// T는 임의의 타입이므로 선언을 조사 못함
								// "rebind<" 에서 < 의 의미를 알수 없음

	typename T::template rebind<int> r2; // ok
	
	// 핵심 : 위 코드에서 "typename", "template" 이 필요한 이유를 알아두세요
}




int main()
{
	Object obj;
	foo(obj);
}