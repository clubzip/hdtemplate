#include <iostream>

template<typename T, T N>
struct integral_constant
{
	static constexpr T value = N;
};

using true_type = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;

// ���� ���� ǥ���� is_pointer �� �Ʒ�ó�� ����� �˴ϴ�.
template<typename T> struct is_pointer     : false_type {};
template<typename T> struct is_pointer<T*> : true_type {};//value=true �� �־������ �ʳ��� ?
										// : integral_constant<bool, true> �̰�
										//	  ^ �� �ȿ� value = N �� �ֽ��ϴ�.
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
	// is_pointer::value �� �ƴ� is_pointer<T> Ÿ���� ��ü ����
	printv_imp(value, std::is_pointer<T>() );
}


int main()
{
	int n = 10;
	printv(&n);
	printv(n);

}
