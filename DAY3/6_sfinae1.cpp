#include <iostream>

// 231 page

// template<typename T> 
// void fn(T   a) { std::cout << " T " << std::endl; } 

// void fn(int a) { std::cout << "int" << std::endl; } 

void fn( ... ) { std::cout << "..." << std::endl; }


int main()
{
	fn(3);	// 1. fn(int) 버전 사용
			// 2. int 버전이 없다면 fn(T) 사용
			// 3. int 버전, T버전 모두 없다면 fn(...) 사용
			// 4. ... 도 없다면, 함수를 찾을수 없다는 에러 발생			
			
	// 핵심 : 위 코드의 함수 찾는 순서 알아 두세요. 			
}
