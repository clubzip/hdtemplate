#include <iostream>

// f1, f2 �� �߿��� �˰����� �ۼ��ߴµ�..
// => ������ �߿��մϴ�.!
void f1(int n) {}
void f2(int n, double d) {}
void f3() {}

// �Ʒ� ó�� �������� ���ø����� �����, ���ڰ� � ���¶�
// ����ð��� �����Ҽ� �ִ� �������� �Լ��� ����� �ֽ��ϴ�.
// => �������� ���ø��� ����ϴ� ��ǥ���� ��Ÿ��.. 
/*
template<typename F, typename ... ARGS>
inline void chronometry(F f, ARGS ... args)
{
	f(args...);  
}
*/

// �����δ� �̷� ������ C++11 �� "�Ϻ��� ����" ����� �ؾ� �մϴ�.
// => "modern C++" ���� ����. 
template<typename F, typename ... ARGS>
inline void chronometry(F f, ARGS&& ... args)
{
	f(std::forward<ARGS>(args)...);
}

int main()
{
	chronometry(f1, 10);	// f1(10)
	chronometry(f2, 10, 20);// f2(10, 20)
	chronometry(f3 );		// f3()
}
