#include <iostream>
#include <vector>
#include <array>

// C++ 표준의 std::array 를 직접 만들어 봅시다.
// 1. 구조체 안에 배열이 있으면 main 함수 1번째 줄 처럼 초기화 가능합니다.
// => 단, 어떠한 생성자라도 없어야 가능합니다.
// => = { } 로 초기화 가능한것을 aggregate type 이라고 합니다.

// 2. 타입과 인자를 템플릿 인자로 받아서 사용자가 변경할수 있게

// 3. 일반 배열과 차이점은 뭔가요 ?
// => 다양한 멤버 함수를 제공할수 있습니다.

template<typename T, std::size_t N>  // std::size_t : unsigned int
struct array
{
	T buff[N];

	std::size_t size() const { return N; }

	// STL 처럼 반복자 지원 가능
	using iterator = T*;

	iterator begin() { return buff; }
	iterator end()   { return buff + N; }

	T& operator[](int idx) { return buff[idx]; }
};

int main()
{
	array<int, 5> arr = { 1,2,3,4,5 };

	std::cout << arr.size() << std::endl;
	arr[0] = 10;

	auto p1 = arr.begin();
	auto p2 = arr.end();

	// vector     : 크기 변경가능. 멤버 함수 제공
	// std::array : 크기 변경안됨. 멤버 함수 제공
	// raw array  : 크기 변경안됨. 멤버 함수 없음.  <== 가장 불편!!!
}
