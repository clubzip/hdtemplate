template<typename T>
struct Object
{
	template<typename U>
	static void mf() {	}
};
// Object<double> �� ��쿡�� �ٸ� ���� ����. 
template<>
struct Object<double>
{
	static constexpr double mf = 3.4;
};

int main()
{
	// Object<T> ���� T�� � Ÿ���̶�
	// �ᱹ mf �� �Լ� ���ø� �ƴѰ��� ??
	// ��?? �����Ϸ��� mf �� �˼� ������ ???
	// => template Ư��ȭ ���� ������..
	Object<int>::mf<int>();
	double d = Object<double>::mf;

	// T�� ���ø� �����϶�
//	Object<T>::mf    // T�� ���� mf �� �Լ� ���ø� �ϼ��� �ְ�
					 // ����(���)�ϼ��� �ֽ��ϴ�.
}
// ��� : typename �� �ݵ�� �˾ƾ� �մϴ�. �ʹ� ���� ���˴ϴ�.
//       template �� ���� �������� ������, �� �ʿ� ���� �˾Ƶμ���