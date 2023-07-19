#include <iostream>

// class template 에서 멤버 함수의 선언과 구현의 분리
template<typename T>
class Vector
{
	T* ptr;
	std::size_t  size;
public:
	Vector(std::size_t sz);
	~Vector();
	T& operator[](std::size_t idx);
};
// 클래스 템플릿의 멤버 함수를 외부에 구현하는 모양
// 1. 클래스 이름은 "Vector" 가 아닌 "Vector<T>" 입니다.
// 2. "T" 라는 타입 인자는 "클래스 템플릿 선언" 안에서만 사용가능
//    멤버 함수를 외부에 구현할 경우 다시 "template<typename T>" 필요

// 3. 멤버 함수를 클래스템플릿 외부에서 구현할수 있지만
//    별도의 소스파일(.cpp) 로 분리하지 마세요
//    모든 함수의 구현은 반드시 헤더에 같이 있어야 합니다.
//    => 그래야, 컴파일 시에 코드 생성 이 가능합니다.
//    => 단, 명시적 인스턴스화 하면 가능은 합니다.(일반적인 코드는 아님)

template<typename T>
Vector<T>::Vector(std::size_t sz) : size(sz)
{
	ptr = new T[sz];
}

template<typename T>
Vector<T>::~Vector()
{
	delete[] ptr;
}

template<typename T>
T& Vector<T>::operator[](std::size_t idx)
{
	return ptr[idx];
}


int main()
{

}
