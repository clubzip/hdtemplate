// move_구현.cpp
#include <iostream>

class String
{
public:
	String(const char* s) {}
	String(const String& s) { std::cout << "copy ctor" << std::endl; }
	String(String&& s)      { std::cout << "move ctor" << std::endl; }
};

int main()
{
	String s1 = "hello";
	String s2 = s1; // copy
	String s3 = std::move(s1); // move
	String s4 = static_cast<String&&>(s2); 
				// std::move 는 결국 위코드 처럼 rvalue 캐스팅입니다.
}