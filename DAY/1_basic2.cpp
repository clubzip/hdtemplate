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
auto square3(auto a)
{
	return a * a;
}
int main()
{
	square3<int>(3);
}