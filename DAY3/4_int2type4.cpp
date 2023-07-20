#include <iostream>
#include <type_traits>

// int2type : ������ ������� ������ Ÿ���� ����� ����
template<int N>
struct int2type
{
	enum { value = N };
};


template<typename T>
void printv_imp(const T& value, int2type<1> )
{
	std::cout << "pointer version : " << value << " : " << *value << std::endl;
}

template<typename T>
void printv_imp(const T& value, int2type<0> )
{
	std::cout << "not pointer version : " << value << std::endl;
}

template<typename T>
void printv(const T& value)
{
	printv_imp(value, int2type< std::is_pointer<T>::value >()  );
	//					0 => int2type<0>
	//					1 => int2type<1>
	//	int2type<0> �� Ÿ��,  "int2type<0>()" �� �ӽð�ü�� ���� ��
}


int main()
{
	int n = 10;
	printv(&n);
	printv(n);

}


