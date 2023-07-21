#include <iostream>
#include "tuple.h"


// 1. primary template
template<int N, typename T> struct tuple_element
{
	using type = T;
};

// 2. N == 0 일때, 0번째 요소의 타입을 구할수 있도록 부분 특수화가 핵심!
template<typename T, typename ... Types> 
struct tuple_element<0, tuple<T, Types...> >
{
	using type = T;
};

// 3. N != 0 일때는 "recursive 로 해서 N == 0"일 될때까지 반복

template<int N, typename T, typename ... Types>
struct tuple_element<N, tuple<T, Types...> >
{
	using type = typename tuple_element<N-1, tuple<Types...>>::type
};


template<typename T>
void fn(T& tp)
{
	// T : tuple<int, double, char>

	typename tuple_element<0, T>::type n1; // int
	typename tuple_element<1, T>::type n2; // double

	std::cout << typeid(n1).name() << std::endl; 
	std::cout << typeid(n2).name() << std::endl;
}

int main()
{
	tuple<int, double, char> t(1, 3.4, 'A');

	fn(t);
}
