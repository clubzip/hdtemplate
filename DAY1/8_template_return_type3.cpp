#include <iostream>

// ��� 3. 2���� ���ڸ� ���� �ٸ� Ÿ���� �ǵ���

template<typename T1, typename T2>
? add(const T1& a, const T2& b)
{
	return a + b;
}

int main()
{
	std::cout << add(3, 4) << std::endl;

	std::cout << add(3.1, 4.3) << std::endl;

	std::cout << add(3, 4.3) << std::endl;
	
}


