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
}