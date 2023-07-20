#include <iostream>

class String
{
public:
	String(const char* s) {}
	String(const String& s) { std::cout << "copy ctor" << std::endl; }
	String(String&& s) { std::cout << "move ctor" << std::endl; }
};

template<typename T>
T&& move(T& obj)
{
	return static_cast<T&&>(obj);
}

int main()
{
	String s1 = "hello";
	String s2 = s1; 
	String s3 = move(s1); 

	// 위처럼 move 를 만들면, 임시객체를 전달할수 없게 됩니다.
	String s4 = move( String("hello") );
}