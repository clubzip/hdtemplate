#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>

template<typename T, 
	     template<typename> class C = std::deque >
class stack
{
//	C c;     // error. C 는 타입이 아닌 템플릿
	C<T> c;
public:
	void push(const T& value) { c.push_back(value); }
	void pop() { c.pop_back(); }
	T& top() { return c.back(); }
};

int main()
{
	// C++ 표준은 아래 처럼 사용해야 합니다.
	// => int 를 2번 표기해야 하므로 중복이 있습니다.
	std::stack<int, std::list<int>> s1; 

	// 아래 처럼 사용가능하도록 stack 을 만들어 봅시다.
	stack<int, std::list > s2; 
	stack<int, std::vector > s3;
}

