#include <vector>
#include <queue>
#include <list>

// 핵심 1. vector 는 앞쪽으로 "삽입/삭제" 할수 없습니다.

/*
class queue
{
	std::vector<int> c;
public:
	void push(int a) { c.push_back(a); } // ok
	void pop() { c.pop_front(); } // error
								  // vector 에는 pop_front()없습니다.
};
*/
/*
template<typename T>
class queue
{
	std::vector<T> c;
public:
	void push(T a) { c.push_back(a); } // ok
	void pop()     { c.pop_front(); } // pop() 을 사용하지 않으면
								// 이 부분이 인스턴스화 되지 않으므로
								// 에러가 아닙니다.
};
*/

// 실제 STL의 queue는 아래 처럼, 컨테이너 자체를 교체 가능하게 되어 있습니다. 
template<typename T, typename C = std::deque<T> >
class queue
{
	C c;
public:
	void push(T a) { c.push_back(a); } // ok
	void pop()     { c.pop_front(); } 
};

int main()
{
//	queue<int> q;
//	q.pop();	// 이 코드가 있어야 queue::pop() 이 인스턴스에 포함되고
				// c.pop_front() 때분에 에러가 발생합니다.

	// STL queue 사용하기
	std::queue<int> q1; // 내부적으로 std::deque 사용
	std::queue<int, std::list<int> > q2; // list 로 변경
	std::queue<int, std::vector<int> > q3; // error. vector는
								// queue 내부 자료구조로 사용할수 없습니다.
}