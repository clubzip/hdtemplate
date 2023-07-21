#include <iostream>
#include <vector>



template<typename ... Types>
void fn(std::vector<int>& v, Types ... args)
{
	// pack 안의 모든 요소를 v 에 넣고 싶다.
	// => 1번째 인자인 v 에
	// => args 안에 있는 모든 요소를 push_back 으로 넣고  싶다...
	(v.push_back(args), ... ); // v.push_back(1), v.push_back(2)
}
int main()
{
	std::vector<int> v;

	fn( v, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	for (auto e : v)
		std::cout << e << ", ";
}
// 이외에도 "구글에서 C++ fold expression example" 하면
// 많은 좋은 예제들을 볼수 있습니다.


