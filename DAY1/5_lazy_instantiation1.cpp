// 32 page, lazy instantiation

// �Ʒ� �ڵ尡 �� �������� ������ ������
class Object
{
	int value;
public:
	void mf()
	{
		*value = 10;	// value �� int Ÿ���̹Ƿ�
						// *value ������ �Ҽ� �����ϴ�.
	}
};

int main()
{
	Object obj;
}
