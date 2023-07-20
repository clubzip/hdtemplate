// is_pointer1.cpp 복사
#include <iostream>
#include <type_traits>

template<typename T>
void printv(const T& value)
{
	if (std::is_pointer_v<T>)
		std::cout << value << " : " << *value << std::endl;
	else
		std::cout << value << std::endl;
}

int main()
{
	int n = 10;
	printv(&n);
	printv(n);	
	// => 이순간 아래처럼 printv가 생성됩니다.
	//    printv(const int& value )
	//    {
	//		if (false)
	//			std::cout << value << " : " << *value  <<=== 이 부분에서 컴파일 에러
	//		else
	//			std::cout << value << std::endl;
	//    }
	// 해결책 : 조건을 만족하지 못하면 
	//         => 실행에서 제외 하는 것이 아니라
	//		   => 인스턴스화에 포함되지 않아야 합니다.
}


