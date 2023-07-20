#include <iostream>
#include <string>

// enable_if ���
// �Ϲ� �Լ� : ���� ��ȯ Ÿ�� ��ġ�� ����մϴ�.
//            ���ڿ� ����ص� ������, �ڵ尡 ������ ���Դϴ�.

// ������ : ��ȯ Ÿ���� �����ϴ�.
//          �׷���, ���ø� ���ڿ� ���� ����մϴ�.



class Animal {};
class Dog : public Animal {};

template<typename T> class smart_ptr
{
	T* obj = nullptr;
public:
	explicit smart_ptr(T* p) : obj(p) {}

	// enable_if �� ����ؼ�
	// U* => T* �� ���� �ɼ� ���ٸ�
	// "���ø� ��ü�� ������� ���ϰ� �ϸ� ���� �޼����� ���� �����ϴ�."

	// �Լ� ������ ������ �ƴ�, �Լ� ������ü�� �ɼ� ������

//	template<typename U,
//	         typename K = std::enable_if_t<����> > // ������ �����ϸ� ����Ʈ�� void
												   // �������� ���ϸ� ġȯ ����. ������
	// 6���ҽ��� ���ڵ�(7��)�� ���� �޽��� �������� Ȯ���� ������
	template<typename U,
		typename K = std::enable_if_t< std::is_convertible_v<U*, T*> > > 

	smart_ptr(const smart_ptr<U>& sp) : obj(sp.obj) {}

	template<typename> friend class smart_ptr;
};
int main()
{
	smart_ptr<Dog>    p1(new Dog);
	smart_ptr<Animal> p2 = p1;	

	smart_ptr<int> p3 = p1;		// error. Dog* => int* �� ���� �ɼ� �����ϴ�.						   
}
// github.com/aosp-mirror  ����
// platform system core    �������丮 �����ϼ���
// libutils/include/utils/typehelpers.h  ���� ������
// copy_type �Լ� ã�� ������.. 

