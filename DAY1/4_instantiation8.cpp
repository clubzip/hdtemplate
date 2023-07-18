#include <iostream>
#include <functional>
#include <type_traits> // std::type_identity

// 27page. identity
// => �Ʒ� ����� 
// => ���� ���� "identity" ��� �̸����� ���Ǿ����ϴ�.
// => �׷���, C++20 ���� ǥ�ؿ� ���ԵǾ��µ�. 
//    �̸��� "std::type_identity" �� �Ǿ����ϴ�.
template<typename T> struct type_identity
{
	using type = T;
};
// type_identity<int>::type    => int
// type_identity<double>::type => double


template<typename T> void foo(T a)
{
}

template<typename T> 
//void goo(T a)
//void goo( typename type_identity<T>::type a)
void goo(typename std::type_identity<T>::type a)
{
}
// goo<int>(3); // type_identity<int>::type �̹Ƿ� �ᱹ goo(int a)
// goo(3);      // 3���� ���� Ÿ���� �߷��ؾ� �ϴµ�.
//				// type_identity ����ü ���ø� �̹Ƿ� 
//				// �����ڳ� deduction guide ���̴� �߷� �ȵ�.
//				// ���� error


int main()
{
	// �ٽ� 1. �Լ� ���ø��� Ÿ���� �����ص� �ǰ� �����ص� �˴ϴ�.
	// => �����ϸ� �����Ϸ��� �Լ� ���ڸ� ���� Ÿ���� �߷��մϴ�.
	foo(10);		// ok
	foo<int>(10);	// ok

	// �ٽ� 2. �����Ϸ��� ���� Ÿ�� �߷��� ���� �������� �ֽ��ϴ�.
	// => std::forward<T>() �� �� ����� ����մϴ�.

	goo(10);	  // error. ������ �ϰ� �ʹ�.
	goo<int>(10); // ok
}