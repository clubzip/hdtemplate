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
	
	f1(3, 3.3); // error. Ÿ�� ���ڰ� �����Ǿ����Ƿ�
				// �Լ� ���ڷ� Ÿ���� �߷��ؾ� �ϴµ�.
				// 1��° ���ڷ� �߷��ϸ� : T=int
				// 2��° ���ڷ� �߷��ϸ� : T=double
				// ����, �����Ϸ��� Ÿ�� �߷� ���մϴ�. error

	f2(3, 3.3); // 1��° ���ڷ� T=int �� �߷�
				// 2��° ���ڴ� "std::type_identity<int>::type" �̹Ƿ�
				// f2(int, int) �ε�. 3.3 �� int�� ���� ����

				// ��, f2�� 2��° ������ Ÿ���� ������
				// 1��° ���ڷ� ��ȯ������ Ÿ���̸� ok.!
}