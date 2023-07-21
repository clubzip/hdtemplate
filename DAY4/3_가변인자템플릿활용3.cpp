#include <iostream>

// �Լ��� ��ȯ Ÿ�� ���ϱ�

// �ٽ� 1. ����(�Ǵ� �Լ�)���𹮿��� �̸��� �����ϸ� "Ÿ��" �� �˴ϴ�.

// �Լ� f �� Ÿ���� �ֽ��ϴ�. 
// f�� Ÿ�� : int(int, double) 

int f(int a, double b)
{
	return 0;
}

//---------------------------------------------

// �ᱹ argument �� �Ʒ� 2���� �κ� Ư��ȭ�� ����ϰ� �˴ϴ�.
// �̷����� ���� primary version �� ���� �ϼ���
template<int N, typename T> struct argument;


template<typename R, typename A1, typename ... ARGS>
struct argument< 0, R(A1, ARGS...) >
{
	using type = A1;
};

template<int N, typename R, typename A1, typename ... ARGS>
struct argument< N, R(A1, ARGS...) >
{
	using type = typename argument<N - 1, R(ARGS...)>::type;
};



template<typename T> void foo(T& a)
{
	// T : int(int, double) �Դϴ�.
//	typename argument<0, T>::type n;  // int
	typename argument<1, T>::type n;  // double

	std::cout << typeid(n).name() << std::endl;
}

int main()
{
	foo(f);
}
