template<typename T>
struct Object
{
	using type = T;
	template<typename U>
	static void mf() {	}
};

template<typename T>
void foo()
{
	// 1. typename 
	Object<int>::type t1; // ok.  int t1
						  // T �� ��������� ����..
						  // type �� dependent name �ƴ�
						  // typename �ʿ� ����.
							
	// �Ʒ� 2���� ��� T�� �����մϴ�. dependent name �Դϴ�.
	// typename �ʿ�
//	typename T::type t;			// �������� ������,
								// main ���� T=int �� �����ϹǷ�
								// int::type t �� �ν��Ͻ�ȭ ����

	typename Object<T>::type t2;// Object<int>::type t2 �̹Ƿ�
								// �ᱹ int t2;
	
	// 2. template
	Object<int>::mf<double>();	// ok. 
								// T �� ����� ���� ����..
								// dependent name �ƴ�.

//	Object<T>::mf<double>(); // mf �� dependent name!!
							 // ������ mf �� Ÿ���� �̸��� �ƴ�
							 // => typename �ʿ� ����.
							 // �׷���, "mf<" ���� "<" �� �ǹ��ľ��� �ȵ�
							//  => �׷��� mf �� ���ø� �̶�� �˷��־�� ��

	Object<T>::template mf<double>(); // ok.
						// Ŭ���� ���ø��� ��� �Լ����ø��� T�� �����ؼ�
						// ȣ���ϴ� ���!
}

int main()
{
	foo<int>();
}