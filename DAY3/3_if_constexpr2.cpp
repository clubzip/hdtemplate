// is_pointer1.cpp ����
#include <iostream>
#include <type_traits>

template<typename T>
void printv(const T& value)
{
	if (std::is_pointer_v<T>)
		std::cout << value << " : " << *value << std::endl;
	else
		std::cout << value << std::endl;
}

int main()
{
	int n = 10;
	printv(&n);
	printv(n);	
	// => �̼��� �Ʒ�ó�� printv�� �����˴ϴ�.
	//    printv(const int& value )
	//    {
	//		if (false)
	//			std::cout << value << " : " << *value  <<=== �� �κп��� ������ ����
	//		else
	//			std::cout << value << std::endl;
	//    }
	// �ذ�å : ������ �������� ���ϸ� 
	//         => ���࿡�� ���� �ϴ� ���� �ƴ϶�
	//		   => �ν��Ͻ�ȭ�� ���Ե��� �ʾƾ� �մϴ�.
}


