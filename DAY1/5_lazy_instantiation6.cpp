
// if : 실행시간 조건문
//	    조건식이 컴파일할때 false 로 결정되어도
//		if 문의 문장은 "인스턴스화에 포함"됩니다.
//		단지, 실행만 안됩니다.

// if constexpr : 컴파일 시간 조건문
//				  조건식은 반드시 컴파일 할때 결과를 알수 있어야 한다.
//				  조건식이 false라면 "인스턴스화를 하지 말라" 는 의미
// 
// 아래 코드는 에러가 있을까요 ?
template<typename T>
void fn(T value)
{
//	if ( false )
	if constexpr ( false )
		*value = 10;
}

int main()
{
	int n = 10;
	fn(n);
}
