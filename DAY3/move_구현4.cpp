#include <iostream>
#include <type_traits>
class String
{
public:
	String(const char* s) {}
	String(const String& s) { std::cout << "copy ctor" << std::endl; }
	String(String&& s) { std::cout << "move ctor" << std::endl; }
};
/*
// Ÿ�� �߷��� ������ ������
// "T&& obj = �Լ�����" ����
//								T			T&&
// �Լ����ڰ� lvalue(s1)		 :	String&	    String& && => String&
// �Լ����ڰ� rvalue(�ӽð�ü) :  String		String&&

template<typename T>
T&& move(T&& obj)
{
	return static_cast<T&&>(obj);
}
*/

template<typename T>
constexpr std::remove_reference_t<T>&& move(T&& obj) noexcept
{
	// static_cast<T&&>(obj) : T�� ������ �����ߴٸ� rvalue ĳ������ �ƴ�
	//						   lvalue ĳ������ �ɼ��� �ֽ��ϴ�.
	
	// �Ʒ� ó�� �ϸ�
	// 1. T�� ���� ��� reference �� ���� �����ϰ�
	// 2. �ٽ� && �� �ٿ��� ĳ�����ϹǷ�
	// 3. rvalue ĳ�������� �����Ҽ� �ֽ��ϴ�.
	return static_cast<std::remove_reference_t<T> &&>(obj);
}

int main()
{
	String s1 = "hello";
	String s2 = s1;			
	String s3 = move(s1);	
	String s4 = move(String("hello"));
}