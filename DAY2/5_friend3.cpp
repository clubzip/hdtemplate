#include <iostream>

template<typename T> 
void fn(T a)   { std::cout << "T" << std::endl; }

void fn(int n); // { std::cout << "int" << std::endl; }


int main()
{
	fn(3.3);	// fn(T) 버전 사용

	fn(3);		// fn(int) 버전 사용
				// fn(int) 버전이 없다면 : fn(T) 버전 사용
				// fn(int) 버전이 선언만 있다면 => fn(int)를 찾을수 없어서 링크에러
}
