
// 77 page
struct Object
{
	using type = int;	// int 의 별명(타입)
	static constexpr int value = 10; // static 멤버 데이타(값)
};

template<typename T>
void foo(T obj)
{
	// 아래 코드에서 * 연산자의 의미를 생각해 보세요

	// 핵심 1. "클래스이름::이름" 의 표현식에서 "이름" 의 의미는
	// 1. 값   : static 멤버 데이타, enum 상수 등
	// 2. 타입 :  using 또는 typedef, nested class

	Object::value * 10;	// 10 * 10   즉, * 는 곱하기 연산자
	Object::type  * p1; // int* p1   즉, * 는 포인터 변수의 선언을 위한 연산자
	

	T::value * 10;	
	T::type  * p2;
}




int main()
{
	Object obj;
	foo(obj);
}