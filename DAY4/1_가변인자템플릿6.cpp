#include <iostream>

// 방법 2. recursive 유사 코드
// => 모든 인자를 가변인자로 하지 말고
// => 1번째 인자는 독립된 인자를 사용합니다.

// 주의!!!
// => 아래 코드는 재귀 호출 아닙니다.
// => foo(3개인자) => foo(2개인자) => foo(1개 인자)
// => 즉, 인자가 다른 foo 함수가 여러개 생성된것!
// => "foo" 함수가 큰 경우는 절대 사용하지 마세요!!
// => 구현이 간단해서 인라인 치환이 가능할때 사용하는 기술

void foo() {}	// 재귀의 종료를 위해서 (C++11 스타일)

template<typename T, typename ... Types>
void foo(T value, Types ... args)
{
	static int n = 0;
	++n;
	std::cout << n << " : " << value << std::endl;

//	foo(args...); // foo(3.4, 'A')
				  // foo('A')		// value : 'A',  args : 				  
				  // foo()

	// C++17 부터는 아래 처럼 하면 재귀 종료를 위한 
	// 인자 없는 foo()가 필요 없습니다.
	if constexpr (sizeof...(args) > 0)
		foo(args...);
}

int main()
{
	foo(1, 3.4, 'A'); 
}





