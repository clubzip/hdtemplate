#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>

// 아래 코드는 allocator 도 변경가능하게 인자로 만든 코드입니다.
template<typename T,						
	     template<typename, typename > class C = std::deque,
	     typename Alloc = std::allocator<T>> 
class stack
{
	C<T, Alloc> c;

public:
	void push(const T& value) { c.push_back(value); }
	void pop() { c.pop_back(); }
	T& top() { return c.back(); }
};
int main()
{
	stack<int, std::vector> s1;
	stack<int> s2;

	stack<int, std::vector, std::allocator<int> > s3;
						// 도전 과제. std::allocator<int> 가 아닌
						//           std::allocator 를 사용하게 변경해 보세요
}

