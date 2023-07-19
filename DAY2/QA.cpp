// QA.cpp

template<typename T, int N>
struct Object 
{
	T buff[N]; 
};

int main()
{
	const int c = 10;
	
	Object<int, c> obj1;	// ���⼭ c�� ����ϰ�
	
	// �� ������ ������ �ϸ� �����Ϸ��� �Ʒ� Ŭ������ �����մϴ�.
	/*
	// => �ٽ� ������ �ڵ忡 "c" ��� �̸��� ����ϴ� ���� �ƴ϶� 
	// => ������ ������ c�� ���� ���� ������ �ڵ带 �����մϴ�.
	struct Object
	{
		int buff[10];
	};
	*/

	// �پ��� ������� ������ c�� ���� �����ϸ� ��� �ǳ��� ?
	*(const_cast<int*>(&c)) = 20;
				// => ����, �̷��� const �� ������ �����ϴ� ����
				// => "undefined" �Դϴ�.
}
