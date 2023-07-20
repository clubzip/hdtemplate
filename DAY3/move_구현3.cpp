#include <iostream>

class String
{
public:
	String(const char* s) {}
	String(const String& s) { std::cout << "copy ctor" << std::endl; }
	String(String&& s) { std::cout << "move ctor" << std::endl; }
};

// 템플릿 만들때 인자로
// T  : 복사본 만들겠다는 의도
// T& : 복사본 만들지 않겠다는것, 단, lvalue 만 가능. 임시객체 받을수 없음
// T&&: 복사본 만들지 않겠다는것, lvalue, rvalue 모두 받겠다는 의도!!

template<typename T>
T&& move(T&& obj)
{
	return static_cast<T&&>(obj);
}

int main()
{
	String s1 = "hello";
	String s2 = s1;			// copy
	String s3 = move(s1);	// move 나와야 하는데 copy 로 잘못나오게됩니다.
	String s4 = move(String("hello")); // move
}