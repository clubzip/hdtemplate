// square.cpp
#include "square.h"

template<typename T> T square(T a)
{
	return a * a;
}

// 여기에서 명시적 인스턴스화를 해놓으면
// 다른 파일에서 square 사용가능합니다.
template int square(int);
template double square(double);

// 단, 이경우 square(int), square(double) 만 사용가능하고
// 다른 타입으로 사용시 에러!!

