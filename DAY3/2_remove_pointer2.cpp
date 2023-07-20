#include <iostream>
#include <type_traits>

// 변형된 타입을 얻는 traits 를 만드는 방법

// 1. primary template 을 만들고 "using type = T" 를 넣으세요

template<typename T> struct remove_pointer
{
	using type = T; // typedef T type 과 동일
};

// 2. T 가 원하는 타입이 될수 있도록, 부분 특수화를 통해서 
//    타입을 분할 합니다. "int*" => "int" 와 "*" 로 분할

template<typename T> struct remove_pointer<T*>
{
	using type = T; 
};

template<typename T> void foo(T a)
{
	remove_pointer<int*>::type n1; // int

	std::cout << typeid(n1).name() << std::endl;

	// 핵심!! : T에 대해서 remove_pointer 사용시 typename 필요 합니다.
	//			"dependent name!"

	typename remove_pointer<T>::type n2; 


	// 단, is_pointer 는 필요 없습니다. 타입이 아닌 값
	bool b = std::is_pointer<T>::value; // ::value 는 타입이 아닌 값!
}



int main()
{
	int n = 0;
	foo(&n);
}
