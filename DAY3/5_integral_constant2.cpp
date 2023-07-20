#include <iostream>

/*
template<typename T, T N>
struct integral_constant
{
	static constexpr T value = N;
};

using true_type = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;

// 이제 실제 표준의 is_pointer 는 아래처럼 만들게 됩니다.
template<typename T> struct is_pointer     : false_type {};
template<typename T> struct is_pointer<T*> : true_type {};//value=true 가 있어야하지 않나요 ?
										// : integral_constant<bool, true> 이고
										//	  ^ 이 안에 value = N 이 있습니다.
*/
#include <type_traits> // 이 헤더 안에 위 코드가 있습니다

//--------------------------------------------------------
template<typename T>
void printv_imp(const T& value, std::true_type )
{
	std::cout << "pointer version : " << value << " : " << *value << std::endl;
}
template<typename T>
void printv_imp(const T& value, std::false_type )
{
	std::cout << "not pointer version : " << value << std::endl;
}

template<typename T>
void printv(const T& value)
{
	// is_pointer::value 가 아닌 is_pointer<T> 타입의 객체 생성
	printv_imp(value, std::is_pointer<T>() );
}


int main()
{
	int n = 10;
	printv(&n);
	printv(n);

}
