#include <vector>
#include <list>


template<typename T>
class List
{
public:
	List() {}
	List(int sz, const T& value) {}

	// STL 컨테이너를 받을수 있는 생성자
	template<typename C>
	List(const C& c) {}
};

// C++17 "class template type deduction guide" 문법
// => 생성자 모양에 따라 타입을 추론하는 방법을 알려주는 문법
// 
// 생성자 모양 -> List<타입>
List() -> List<int>;		// 디폴트 생성자 사용시는 T=int로 해달라
							// 물론, 이경우는 에러가 더 좋습니다.

template<typename C>		// 현재 C = vector<int>
List(const C& c) -> List< typename C::type >;


int main()
{
	List<int> s1(10, 3); // ok. 타입을 명시적으로 전달
	List      s2(10, 3); // ok. C++17 부터는 생성자 인자를 통해서
						 //     T의 타입이 추론됨. T=int
	List<int> s3;	// ok. 타입을 명시적으로 전달
	List      s4; 
	
	// 아래 코드를 지원해 봅시다.
	std::vector v = { 1,2,3 };
	List s5(v); // v 의 타입은 "vector<int>" 입니다.
				// List<int> 로 결정되어야 합니다.
				// 즉, vector<int> 가 저장하는 타입으로 결정되어야 합니다.
				// vector<int>::type 으로 해야 합니다.

//	List s6(v.begin(), v.end());
}

