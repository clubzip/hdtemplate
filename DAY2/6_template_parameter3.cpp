#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>

// 아래 코드는 C++17 부터 가능합니다.
// ~ C++14 까지는 에러.. 
/*
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
*/

// 위 코드가 C++14 까지 에러인 이유
// => STL 의 list, vector 는 인자가 2개인 템플릿 입니다.
/*
template<typename T, typename Ax = std::allocator<T> >
class list
{
};
// std::list<int> s;
*/
// 따라서, 2번째 템플릿 인자는 "인자가 2개인 테플릿" 모양이어야 합니다.
template<typename T,
	     template<typename, typename> class C = std::deque >
class stack
{
	//	C c;     // error. C 는 타입이 아닌 템플릿
	//C<T> c;		// error. C는 인자가 2개인 템플릿
	C<T, std::allocator<T> > c;
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
	s2.push(10);
}

