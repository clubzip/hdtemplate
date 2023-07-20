#include <iostream>

// SFINAE �� �ǹ�
// => Substitution Failure Is Not An Error
// => ġȯ ���д� ������ �ƴϴ�.

// �Լ� ���ڸ� ���� ���ø��� ����ϱ�� �����ߴµ�..
// => ���� �Լ��� ����ٰ�(�ν��Ͻ�ȭ) �����ϸ�!!
// => ������ ������ �ƴϰ�, �ĺ����� ���ܵȴٴ� �ǹ�
// => ���� �̸��� �ٸ� �Լ��� �ִٸ� ���ɼ� �ִٴ� ��

template<typename T> 
typename T::type fn(T  a) { std::cout << " T "; return 0; }
//     int::type fn(int a) {...} �� �Լ��� �����Ϸ��� �ϴµ�..
//						=> int::type �� �߸��� �ڵ尡 �˴ϴ�.
//						=> ��, �Լ� ���� ����!


int fn(... ) { std::cout << "..."; return 0; }


int main()
{
	fn(3); // T ������ ����ϰ� �˴ϴ�.
}
