// 7 page
// 타입 파라미터를 표기하는 방법
// 1번 소스 복사 - square 복사

// 방법 1. class 사용 - C++ 언어가 처음에 사용하던 방식
template<class T>
T square1(T a)
{
	return a * a;
}

// 방법 2. typename
template<typename T>
T square2(T a)
{
	return a * a;
}

// 방법 3. C++20 부터 "auto" 사용가능
// => "template" 이라는 키워드를 사용하지 않았지만
// => 아래 코드는 template 입니다.
// => square1, square2, square3 는 완벽히 동일한 코드입니다.
// => 단, 이경우 T가 없어서 함수 구현안에서 "T"타입을 사용못합니다.
//    
auto square3(auto a)
{
	return a * a;
}
int main()
{
	// 핵심 2. 용어 꼭 기억해 두세요
	// <int> : template argument(parameter) - 컴파일 시간에 전달
	// (3)   : function argument(parameter) - 실행시간에 전달
	square3<int>(3);
}

// g++ 1_basic2.cpp -std=c++20
// 단, PATH 환경변수에 "mingw64\bin" 등록해 놓아야 합니다.