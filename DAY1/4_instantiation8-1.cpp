#include <type_traits> // std::type_identity �� ����� �ʿ�!

// �Ʒ� �Լ� ���ø��� �ݵ�� Ÿ���� ��������� ������ �մϴ�.
template<typename T>
void foo(typename std::type_identity<T>::type)
{
}
// �Ʒ� 2���� ���� ���ô�
template<typename T> 
void f1(T a, T b)
{
}
template<typename T>
void f2(T a, typename std::type_identity<T>::type b)
{
}
int main()
{
//	foo(3); // error
	f1(3, 3.3);
	f2(3, 3.3);
}