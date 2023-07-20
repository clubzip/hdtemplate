#include <iostream>

void fn(...) 
{ 
	std::cout << "..." << std::endl; 
}

// 아래 코드는 SFINAE 가 적용될까요 ? 에러일까요 ?

template<typename T> 
void fn(T a) 
{ 
	typename T::type n;  // int::type n;  이므로
						// 잘못된 코드!!
						// 1. error	
						// 2. SFINAE 에 따라 후보에서 제외,,,
						//			위에 있는 fn(...) 사용
						// 답은 1 번
}

int main()
{
	fn(3); // T=int
}
