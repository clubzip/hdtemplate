#include <iostream>

// ��� 3-3. ��ȯ Ÿ������ auto �� ǥ��!

template<typename T1, typename T2>
auto add1(const T1& a, const T2& b) -> decltype(a + b) 
{
	return a + b;
}

// auto �� ǥ���ص� �˴ϴ�.
template<typename T1, typename T2>
auto add2(const T1& a, const T2& b)
{
	if (a == 1) return a;
	
	return a + b;
}

// add1 vs add2
// add1 : ��ȯ Ÿ���� ����ڰ� ���� �Ѱ� "decltype(a+b)"�� �ش޶��!
//			=> return ������ ������ �־ ����
// 
// add2 : ��ȯ Ÿ���� �����Ϸ��� return ������ ���� �߷��� �޶�� ��
//			=> return ������ �Ѱ��϶��� ����
//			=> return ������ ������ �ִٸ� error

// add1, add2 �� �Ǵٸ� ���̰� �ֽ��ϴ� - ����

int main()
{
	std::cout << add2(3, 4) << std::endl;
	std::cout << add2(3.1, 4.3) << std::endl;
	std::cout << add2(3, 4.3) << std::endl;


}



