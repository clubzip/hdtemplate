template<typename T>
struct Object
{
	template<typename U>
	static void mf() {	}
};
int main()
{
	// Object<T> ���� T�� � Ÿ���̶�
	// �ᱹ mf �� �Լ� ���ø� �ƴѰ��� ??
	// ��?? �����Ϸ��� mf �� �˼� ������ ???
	// => template Ư��ȭ ���� ������..
	Object<int>::mf<int>();
}