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
}




int main()
{
	Object obj;
	foo(obj);
}