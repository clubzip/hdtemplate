


template<typename T>
void fn(T arg)
{

}

int main()
{
	const int c = 10;

	// ���ø��� T�� Ÿ�� ������ "�Լ�����"�� �����մϴ�.
	// �Ʒ� ó�� �����Ҽ� �ֽ��ϴ�.
	fn(c); // T arg = c;

	// auto �� Ÿ�� ������ �캯�� ���� �����մϴ�.
	// ���ø��� ���� ������ ��Ģ �Դϴ�.
	// T arg = c
	auto   a = c;


	auto  a1 = c; // ��Ģ 1. �캯(�Լ�����)�� ���� const, volatile, reference ������ Ÿ�԰���
				  // int a1 = c;

	auto& a2 = c;   // auto& �̹Ƿ� ��Ģ 2. 
					// => �캯(�Լ�����)�� ���� const, volatile ����,  reference ������ Ÿ�԰���
					// auto = const int    a2 = const int&


	int n = 10;

	// auto&& �̹Ƿ� T&& �� ����, ��Ģ 3
	auto&& a3 = 3; // 3�� rvalue    auto(T)=int,   a3 : int&&
	auto&& a4 = n; // n�� lvalue    auto(T)=int&,  a4 : int& && => int&

}