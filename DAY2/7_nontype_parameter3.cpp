#include <iostream>
#include <vector>
#include <array>

// make array
int main()
{
	// 배열과  vector는 모두 []로 요소 접근 가능합니다.
	// 
	// 배열   : 크기 변경 안됨. 멤버 함수 없음.   "모든 요소가 stack에 놓인다."
	// vector: 크기 변경 가능. 다양한 멤버함수.   "모든 요소가 heap 에 놓인다."

	int x[5] = {1,2,3,4,5};

	std::vector<int> v = {1,2,3,4,5};
	
	// vector 가 배열 보다 편리 합니다.
	// => 그런데, 할당/해지 속도는 배열 보다 느립니다.

	// 그래서 C++11 부터, 모든 요소를 stack 에 보관하는 std::array 등장
	std::array<int, 5> arr = { 1,2,3,4,5 };

}
