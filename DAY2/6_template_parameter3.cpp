#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>

template<typename T, 
	     template<typename> class C = std::deque >
class stack
{
//	C c;     // error. C �� Ÿ���� �ƴ� ���ø�
	C<T> c;
public:
	void push(const T& value) { c.push_back(value); }
	void pop() { c.pop_back(); }
	T& top() { return c.back(); }
};

int main()
{
	// C++ ǥ���� �Ʒ� ó�� ����ؾ� �մϴ�.
	// => int �� 2�� ǥ���ؾ� �ϹǷ� �ߺ��� �ֽ��ϴ�.
	std::stack<int, std::list<int>> s1; 

	// �Ʒ� ó�� ��밡���ϵ��� stack �� ����� ���ô�.
	stack<int, std::list > s2; 
	stack<int, std::vector > s3;
}

