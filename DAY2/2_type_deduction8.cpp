template<typename T>
void f1(T a)
{
}

template<typename T>
void f2(T& a)
{
}

int main()
{
	int x[3] = { 1,2,3 };
	int y[5] = { 1,2,3, 4, 5 };

	f1(x);
	f1(y);
	f2(x);
	f2(y);
}
// �� �ڵ带 ������ ������ �Լ��� � �������� ������ ������
// f1 : ? ��
// f2 : ? ��