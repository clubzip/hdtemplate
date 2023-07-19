template<typename T1, typename T2>
struct Object
{
	T1 first;
	T2 second;

	static int cnt;

	Object(const T1& a, const T2& b);
};
// 핵심 : Object 는 template 인자가 2개 입니다.
// 1. Object 의 static 변수인 cnt 를 외부 선언해 보세요


// 2. Object 의 생성자 구현부 만들어 보세요 "first(a), second(b)"로 초기화 하세요




int main()
{
	Object<int, double> obj1(1, 3.4);
}
