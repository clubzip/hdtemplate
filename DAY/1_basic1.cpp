// 5 page

// 함수 오버로딩 : 인자의 갯수나 타입이 다르면 동일이름의 함수를 여러개 만들수 있다.

int square(int a)
{
	return a * a;
}

double square(double a)
{
	return a * a;
}

int main()
{
}


// visual studio 사용시 => visualstudio.net

// 1. 프로젝트 버전 설정해야 합니다.
// => 프로젝트 메뉴, 속성 메뉴 선택

// 2. 파일을 빌드에서 포함/제외 하는 방법

// 3. 빌드하는 방법 : Ctrl + F5

// g++ 사용시 
// g++ 소스이름.cpp -std=c++20 ( 필요한 경우만, 생략시 C++14)

