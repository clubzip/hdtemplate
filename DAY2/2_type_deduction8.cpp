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

	f1(x); // f1(int* a)
	f1(y); // f1(int* a)
	f2(x); // f2(int(&a)[3])
	f2(y); // f2(int(&a)[5])
}
// �� �ڵ带 ������ ������ �Լ��� � �������� ������ ������
// f1 : 1 ��
// f2 : 2 ��