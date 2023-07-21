#include <iostream>

int main()
{
	// C 언어의 printf 는 안전하지 않습니다.
	printf("%d, %d\n", 1);			// 인자 갯수 부족
	printf("%d, %d\n", 1, 2, 3);	// 인자 갯수 초과

	// 위코드는 잘못된 코드인데..
	// 1. 컴파일 에러 없습니다.
	// 2. 실행시간에 예외등이 나오지도 않습니다.

	// => 그냥, 잘못된 결과가 나오거나, runtime error
	// => 즉, undefined(미정의 동작) 발생
}
