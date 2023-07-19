#include <memory>

class Animal { int age; };

class Dog : public Animal {};

int main()
{
	Dog*    pdog    = new Dog;
	Animal* panimal = pdog; // ok.. upcasting
							// 객체지향 언어의 가장 큰 특징!!

	// C++은 포인터 대신 사용하는 스마트 포인터가 있습니다.!!
	std::shared_ptr<Dog>	p1(new Dog);
	std::shared_ptr<Animal> p2 = p1; // 복사(대입)가능해야 합니다.
					// => p1 은  shared_ptr<Dog>
					// => p2 는  shared_ptr<Animal>
					// => 앞에서 배운 "Generic 생성자"가 있어야 합니다.		
					// => shared_ptr 안에 이미 generic 생성자가 있습니다.
}

// 위 기술(Generic 생성자를 사용한 변환)의 이름이 "coercion by member template" 입니다.

// 구글에서 "C++ IDioms" 검색후 1 번째 링크에 가보세요..