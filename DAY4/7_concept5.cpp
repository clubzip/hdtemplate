#include <iostream>
#include <algorithm>
#include <concepts>
#include <vector>


// 값 버전의 find
template<typename IT, typename T>
IT find(IT first, IT last,  T value)
{
	std::cout << "값 버전" << std::endl;

	return first;
}

// 조건자 버전도 find 로 할수 있을지 생각해 봅시다.
// => 함수 모양이 위와 완전히 동일합니다.!!
// => 같은 이름으로 만들수 없습니다.
template<typename IT, typename Pred>
IT find(IT first, IT last, Pred value)
{
	std::cout << "조건자 버전" << std::endl;

	return first;
}



int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	
	// find    : 주어진 구간에서 값 검색
	// find_if : 주어진 구간에서 조건 검색(마지막 인자로 호출가능한 객체(callable object) 전달)

	auto p1 = std::find(std::begin(v), std::end(v), 3);
//	auto p2 = std::find_if(std::begin(v), std::end(v), [](int a) { return a % 3 == 0; } );

	auto p2 = std::find(std::begin(v), std::end(v), [](int a) { return a % 3 == 0; });

}
