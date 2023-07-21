#include <iostream>
#include <vector>
#include <type_traits>

// Concept 문법 - C++20 에서 추가된 아주 중요한 문법!!

template<typename T> void check(T& c)
{
	// T 가 포인터 타입 인지 알고 싶다.
	// => C++11 type traits 사용
	// => template (partial) specialization 기술로 만들게 됩니다.
//	bool b = std::is_pointer_v<T>;


	// T 가 컨테이너인지 알고 싶다.
	// => "컨테이너 인지 조사하려면 어떻게 해야 할까?" 도 중요 하지만, 
	// => "컨테이너" 를 어떻게 정의 해야 할까 ? 가 핵심입니다.!!
	
	// C++20 Concept
	// => 타입이 가져야하는 조건(정의)를 코드로 표현하는 문법
	// traits : is_xxx 로 시작
	// concept : is_ 를 사용하지 말라고 권장..
	//           is_container<T> 가 아닌 container<T>
}



int main()
{
	int n = 0;
	std::vector<int> v = { 1,2,3 };
	int x[3] = { 1,2,3 };

	check(n);	
	check(v);	
	check(x);   
}
