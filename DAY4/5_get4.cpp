#include <iostream>
#include "tuple.h"


template<int N, typename T> struct tuple_element;


// tuple<T, Types...> 에서
// 0번째 요소의 타입               : T
// 0번째 요소를 저장하는 tuple 타입 : tuple<T, Types...>

template<typename T, typename ... Types>
struct tuple_element<0, tuple<T, Types...> >
{
	using type = T;
	using tupleType = tuple<T, Types...>;
};

template<int N, typename T, typename ... Types>
struct tuple_element<N, tuple<T, Types...> >
{
	using type      = typename tuple_element<N - 1, tuple<Types...>>::type;
	using tupleType = typename tuple_element<N - 1, tuple<Types...>>::tupleType;
};
//----------------------------------------------------------------
// get2 에서 한글로 만든 get 복사해오세요

template<int N, typename TP>
typename tuple_element<N, TP>::type &     
get(TP& tp)
{
	return static_cast<typename tuple_element<N, TP>::tupleType&>(tp).value;
}

int main()
{
	tuple<int, double, char> t(1, 3.4, 'A');

	get<0>(t) = 99;

	std::cout << get<0>(t) << std::endl; // 99
	std::cout << get<1>(t) << std::endl; // 3.4
}
