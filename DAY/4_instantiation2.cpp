#include <iostream>

// explicit instantiation 

template<typename T>
T square(T a)
{
	return a * a;
}

// 사용하는 코드를 보고 인스턴스화를 하지 말고
// 명시적으로 인스턴스화 해달라는 요청
// godbolt.org 에 복사해 보세요
template int	square<int>(int a);
template double square<>(double a);
template float	square(float a);

int main()
{

}

