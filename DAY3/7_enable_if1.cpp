// 6_enable_if1.cpp

// 핵심 : enable_if 는 템플릿 인자가 2개 입니다.
//        enable_if<bool값, 타입> 처럼 사용해야 합니다
//        main 주석 생각해 보세요

template<bool, typename T = void > struct enable_if
{
	using type = T;  
};
// 1번째 인자가 false 인 경우를 위한 부분 특수화!
// => 핵심은 type 이 없다는 점입니다.
template<typename T> struct enable_if<false, T> 
{
};

int main()
{
	// 아래 코드에서 n1, n2, n3 의 타입은 ?
	enable_if<true, int>::type  n1; // int n1
	enable_if<true>::type       n2; // void n2  인데, void 형 변수 선언은 안되므로 error
									
	enable_if<false, int>::type n3; // error. ::type 멤버가 없습니다.
								// 즉, enable_if<false...>::type 은 항상 ::type 이 없음
								
}
