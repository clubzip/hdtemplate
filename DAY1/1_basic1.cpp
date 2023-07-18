// 5 page
// 함수 오버로딩 : 인자의 갯수나 타입이 다르면 동일이름의 함수를 여러개 만들수 있다.

/*
int square(int a)
{
	return a * a;
}

double square(double a)
{
	return a * a;
}
*/

// 함수의 구현이 동일(유사)하다면 함수를 여러개 만들지 말고
// 함수를 만드는 "틀(템플릿)"을 제공합니다
// 아래 코드는 "함수"가 아니라 "함수를 만드는 틀" 입니다.
template<typename T> 
T square(T a)
{
	return a * a;
}
int main()
{
	// 함수 템플릿(틀)을 사용하는 정확한 코드
	square<int>(3);		// 1. 컴파일 시간에 필요한 함수생성
						//    int square(int) 함수를 생성
						// 2. 이 위치는 생성된 함수를 호출하는 기계어 생성
						//	  call square<int>(3) 
	square<double>(3.3);// 1. double square(double) 함수 생성
						// 2. call square<double>(3.3) 

	// 함수 템플릿 사용시 타입 인자를 생성하면
	// => 함수 인자를 보고 타입을 결정
	square(3);	// 3을 보고 T=int 로 결정
	square(3.3);// 3.3 을 보고 T= double 로 결정
}
// godbolt.org 사이트에 접속해 보세요
// => 다양한 언어의 코드를 어셈블리 레벨에서 확인할수 있는 사이트

// 코드 폭발(code bloat)
// => template 사용시 너무 많은 함수(클래스)가 생성되어서
//    코드 메모리가 증가하는 현상
// => 임베디드 분야에서는 주의 해야 합니다.

// 하지만 "square" 같은 경우는 inline 또는 constexpr 로 했다면
// => 컴파일러 최적화를 거치면 
// => code bloat 등의 현상은 없습니다.!!
// => 즉, 잘 사용하면 해결할수 있다는 의미.. 