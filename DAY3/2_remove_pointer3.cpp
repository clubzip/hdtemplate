#include <iostream>
#include <type_traits>

template<typename T> struct remove_all_pointer
{
	using type = T; 
};

template<typename T> struct remove_all_pointer<T*>  
{								
	// recursive 입니다.
	// 종료는 T=int 가 될때, primary 버전을 사용하기 때문에 종료됩니다.
	using type = typename remove_all_pointer<T>::type;		
};



int main()
{
	// 1. C++ 표준의 remove_pointer 는 "포인터를 한개" 제거한 타입을 얻게됩니다.
	std::remove_pointer<int***>::type n; // int**


	// 2. 표준에는 없지만, 모든 포인터를 제거하는 traits을 만들어 봅시다.

	remove_all_pointer<int***>::type n2; // int  n2  
}





