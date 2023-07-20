#include <iostream>

// int2type : ������ ����� Ÿ������ ����� �ý���
//			  �ַ� �Լ� �����ε����� Ȱ��
//			  1, 2, 3 ���� ���� ���� �ٸ� �Լ��� �����ϰ� �ϴ� ���
//			  2003�� modern C++ design å�� ������ "�ȵ巹�� �˷���巹��ť"

// C++ǥ������ȸ�� C++11 ���鶧 int2type �� �������Ѽ� ǥ�ؿ� �־����ϴ�.
template<int N>
struct int2type
{
	enum { value = N };
};

// int -> type �� �ƴ϶�, long->type, char->type ���� ��� �����ϱ� ����
// �Ʒ� ó�� ��������ϴ�.
template<typename T, T N>
struct integral_constant
{
	static constexpr T value = N;
};

// �Ʒ� n1, n2, n3 �� ��� �ٸ� Ÿ���Դϴ�.
integral_constant<int, 0> n1;
integral_constant<int, 1> n2;
integral_constant<short, 0> n3;

// true, false �� ���� Ÿ��������, b1, b2 �� �ٸ� Ÿ���Դϴ�.
integral_constant<bool, true> b1;
integral_constant<bool, false> b2;

// true_type, false_type �� �������� ��Ÿ�� "Ÿ��"(���� �ƴ�) �Դϴ�.
// => C++11 ǥ�ؿ� �ֽ��ϴ�.
using true_type  = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;

// ���� ���� ǥ���� is_pointer �� �Ʒ�ó�� ����� �˴ϴ�.
template<typename T> struct is_pointer     : false_type {};
template<typename T> struct is_pointer<T*> : true_type {};