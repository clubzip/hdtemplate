#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>

// STL 의 stack 은 실제로 아래 처럼 구현되어 있습니다.
// => 결국 기존 선형 컨테이너(list, vector, deque)의 함수이름만 변경해서
//    stack 처럼 보이게 만든것
// => "adaptor" 패턴
template<typename T, typename C = std::deque<T> > 
class stack
{
	C c;
public:
	void push(const T& value) 	{ c.push_back(value); }
	void pop()            		{ c.pop_back(); }
	T&   top()            		{ return c.back(); }
};

int main()
{
	std::stack<int> s1;
	s1.push(10); 

	// STL stack 사용시 내부 컨테이너 변경 가능합니다.
	std::stack<int, std::list<int>> s2; // 내부 자료구조로 list 사용해달라는것
	s2.push(20); // 결국. list.push_back(20) 으로 보관하는 코드

	std::stack<int, std::vector<int>> s3;
	s3.push(30); // vector.push_back(30)
}

