#include <iostream>

// Vector vs Vector<T>

template<typename T>
class Vector
{
	T* ptr;
	std::size_t  size;
public:
	Vector(std::size_t sz) : size(sz)
	{
		ptr = new T[sz];
	}
	~Vector() { delete[] ptr; }

	T& operator[](std::size_t idx) { return ptr[idx];}

	// 핵심 3. 다음중 맞는 것은 ?
//	void swap(Vector&    v) {}	// 1. 이렇게 해도 됩니다.!!
//	void swap(Vector<T>& v) {}  // 2. 이 표기법이 정확한 표기법이지만

	// => 멤버가 아닌 함수에서는 "반드시 Vector<타입>" 으로 표기해야 합니다.
	// => 그런데, 멤버 함수 에서는 "Vector" 라고 표기해도 "Vector<T>" 와 같습니다.


	// 그래서 복사 생성자의 모양은 아래 2가지 모두 가능합니다.
//	Vector(const Vector& v) {}     // 이렇게 해도 되고
//	Vector(const Vector<T>& v) {}  // 이렇게 해도 됩니다.(위와 동일)
};


// 핵심 2. 함수 인자를 표기할때는 "템플릿"이 아닌 "타입"을 표기해야 합니다.
//void fn(Vector v) {}		// error
void fn(Vector<int> v) {}	// ok

int main()
{
	// 핵심 1. Vector 와 Vector<int> 차이점
	// Vector      : 타입(class) 가 아닌 class 를 생성하는 틀(template)
	// Vector<int> : 타입 입니다.

	Vector<int> v1(10);	 // ok. 객체를 생성할때는 "타입"을 적어야 합니다.

//	Vector v2(10);	// error. Vector 는 타입이 아닌 template 입니다.
					// 단, C++17 부터는
					// "생성자에 의한 타입 추론" 또는 "deduction guide" 가 있다면 가능


	fn(v1);
}
