#include <iostream>

// step 3. 여러개 보관하기 !!    이 예제의 핵심!!!!

template<typename ... Types>
struct tuple
{
	static constexpr int N = 0;
};

template<typename T, typename ... Types>
struct tuple<T, Types...> : public tuple<Types...>
{
	using base = tuple<Types...>;

	T value;

	tuple() = default;

	tuple(const T& v, const Types& ... args) 
		: value(v), base( args...) {}


	static constexpr int N = base::N + 1;
};




int main()
{
//	tuple<> t0;					 // 보관 안함 - primary 버전 사용
//	tuple<             char> t1; // char  만 보관
//	tuple<     double, char> t2; // double 만 보관

	tuple<int, double, char> t3; // int    만 보관
}
