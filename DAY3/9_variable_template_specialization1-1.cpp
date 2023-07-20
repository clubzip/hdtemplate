#include <iostream>

template<typename T>
constexpr int made_year = -1;

// variable template �����
// => ��κ� "template specialization" ������ ���� ���˴ϴ�.

class Sample
{
};
// Sample �� ���� ����� made_year �� Sample Ÿ������ Ư��ȭ �ؼ�
// ���� ��������� ����(�⵵)�� �˷� �ݴϴ�.
template<>
constexpr int made_year<Sample> = 2023;


int main()
{
	std::cout << made_year<int> << std::endl;	
	std::cout << made_year<double> << std::endl;
	std::cout << made_year<Sample> << std::endl;

}



