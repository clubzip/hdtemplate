
// 53page
template<typename T>
class Object
{
public:
	// �ٽ� 1. Object �� "class template" �Դϴ�.
	// �ٽ� 2. mf1 �� "�Ϲ� ��� �Լ�" �Դϴ�. template �ƴՈ��ϴ�.
	//         mf1 �� ���� Ÿ���� �׻� int �Դϴ�.
	void mf1(int n) {}

	// �ٽ� 3. mf2 �� "�Լ� ���ø�" �� �ƴմϴ�. <== �߿�!!
	//        "class template" �� "�Ϲ� ��� �Լ�" �Դϴ�.
	//         Object<int> obj1; �̼��� mf2�� ���ڴ� int�� ����.
	//		   ��, �Լ��� ȣ��� Ÿ���� �����Ǵ� ���� �ƴ϶�, ��ü ������ ����
	void mf2(T   n) {}

	// �ٽ� 4. mf3 �� "�Լ� ���ø�" �Դϴ�.
	// => "class template �� member function template" �̶�� �θ��ϴ�.
	// => mf3(3)   => mf3(int) ����
	// => mf3(3.3) => mf3(double) ����
	template<typename U>
	void mf3(U n) {}
};

int main()
{
	Object<int> obj1;		// mf2(int)�� ����
	Object<double> obj2;	// mf2(double)�� ����

	// mf1�� ���ڴ� �׻� int Ÿ���Դϴ�.
	obj1.mf1(3);	
	obj2.mf1(3); 

	//
	obj1.mf2(3);	// 
	obj1.mf2(3.4);	// mf2(double)�� �����Ѱ��� �ƴմϴ�.
					// mf2(int) ������ 3.4 �� �����Ѱ�
	
					
	// mf3 �� �Լ� ���ø� �̹Ƿ� "������ Ÿ��"�� ���� "�Լ��� ����" �˴ϴ�.
	obj1.mf3(3);	// mf3(int) ����
	obj1.mf3(3.4);	// mf3(double) ����		
}
