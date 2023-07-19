#include <memory>

class Animal { int age; };

class Dog : public Animal {};

int main()
{
	Dog*    pdog    = new Dog;
	Animal* panimal = pdog; // ok.. upcasting
							// ��ü���� ����� ���� ū Ư¡!!

	// C++�� ������ ��� ����ϴ� ����Ʈ �����Ͱ� �ֽ��ϴ�.!!
	std::shared_ptr<Dog>	p1(new Dog);
	std::shared_ptr<Animal> p2 = p1; // ����(����)�����ؾ� �մϴ�.
					// => p1 ��  shared_ptr<Dog>
					// => p2 ��  shared_ptr<Animal>
					// => �տ��� ��� "Generic ������"�� �־�� �մϴ�.		
					// => shared_ptr �ȿ� �̹� generic �����ڰ� �ֽ��ϴ�.
}

// �� ���(Generic �����ڸ� ����� ��ȯ)�� �̸��� "coercion by member template" �Դϴ�.

// ���ۿ��� "C++ IDioms" �˻��� 1 ��° ��ũ�� ��������..