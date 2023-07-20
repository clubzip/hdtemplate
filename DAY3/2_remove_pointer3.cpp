#include <iostream>
#include <type_traits>

template<typename T> struct remove_all_pointer
{
	using type = T; 
};

template<typename T> struct remove_all_pointer<T*>
{
	using type = T;
};



int main()
{
	// 1. C++ ǥ���� remove_pointer �� "�����͸� �Ѱ�" ������ Ÿ���� ��Ե˴ϴ�.
	std::remove_pointer<int***>::type n; // int**


	// 2. ǥ�ؿ��� ������, ��� �����͸� �����ϴ� traits�� ����� ���ô�.

	remove_all_pointer<int***>::type n2; // int  n2  
}
