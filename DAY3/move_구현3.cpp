#include <iostream>

class String
{
public:
	String(const char* s) {}
	String(const String& s) { std::cout << "copy ctor" << std::endl; }
	String(String&& s) { std::cout << "move ctor" << std::endl; }
};

// ���ø� ���鶧 ���ڷ�
// T  : ���纻 ����ڴٴ� �ǵ�
// T& : ���纻 ������ �ʰڴٴ°�, ��, lvalue �� ����. �ӽð�ü ������ ����
// T&&: ���纻 ������ �ʰڴٴ°�, lvalue, rvalue ��� �ްڴٴ� �ǵ�!!

template<typename T>
T&& move(T&& obj)
{
	return static_cast<T&&>(obj);
}

int main()
{
	String s1 = "hello";
	String s2 = s1;			// copy
	String s3 = move(s1);	// move ���;� �ϴµ� copy �� �߸������Ե˴ϴ�.
	String s4 = move(String("hello")); // move
}