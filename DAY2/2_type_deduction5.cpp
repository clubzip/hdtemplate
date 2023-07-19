


template<typename T>
void fn(T arg)
{

}

int main()
{
	const int c = 10;

	// 템플릿의 T의 타입 결정은 "함수인자"로 결정합니다.
	// 아래 처럼 생각할수 있습니다.
	fn(c); // T arg = c;

	// auto 의 타입 결정은 우변을 보고 결정합니다.
	// 템플릿과 거의 동일한 규칙 입니다.
	// T arg = c
	auto   a = c;


	auto  a1 = c; // 규칙 1. 우변(함수인자)가 가진 const, volatile, reference 제거후 타입결정
				  // int a1 = c;

	auto& a2 = c;   // auto& 이므로 규칙 2. 
					// => 우변(함수인자)가 가진 const, volatile 유지,  reference 제거후 타입결정
					// auto = const int    a2 = const int&


	int n = 10;

	// auto&& 이므로 T&& 와 동일, 규칙 3
	auto&& a3 = 3; // 3은 rvalue    auto(T)=int,   a3 : int&&
	auto&& a4 = n; // n은 lvalue    auto(T)=int&,  a4 : int& && => int&

}