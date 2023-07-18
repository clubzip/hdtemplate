#include <iostream>
#include <type_traits>

// ��� 2. std::type_identity ��� - C++20 �ȵǽø� �տ���(�ν��Ͻ�ȭ8��)
//								����� ������ ������
// => 1��° ���ڷθ� Ÿ���� �����ϰڴٴ� �ǵ�
// => 2��° ������ Ÿ���� 1��° ���� Ÿ������ ��ȯ�����ϸ� ok
template<typename T>
T add(const T& a, const typename std::type_identity<T>::type & b)
{
	return a + b;
}

int main()
{
	std::cout << add(3, 4) << std::endl;
	std::cout << add(3.1, 4.3) << std::endl;

	std::cout << add(3, 4.3) << std::endl; // ok
									// ��, add(int, int) �� ����
									// ���� ����� 7

	std::cout << add<double>(3, 4.3) << std::endl;
}



