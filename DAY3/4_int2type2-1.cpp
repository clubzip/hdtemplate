#include <iostream>
#include <type_traits>


template<typename T>
void printv_imp(const T & value, YES )
{
	std::cout << "pointer version : " << value << " : " << *value << std::endl;
}

template<typename T>
void printv_imp(const T & value, NO)
{
	std::cout << "not pointer version : " << value << std::endl;
}

template<typename T>
void printv(const T& value)
{
	// �Լ� �����ε��� ����ؼ� ���ǿ� ���� "�ٸ� �Լ�"�� ȣ���մϴ�.
	printv_imp(value, std::is_pointer<T>::value  );
						// T �����Ͷ��   : true ��, 1
						// T �����;ƴϸ� : false ��, 0
}


int main()
{
	int n = 10;
	printv(&n);
	printv(n);

}

