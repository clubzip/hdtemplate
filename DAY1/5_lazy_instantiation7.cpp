// 템플릿은 틀 입니다.
// 사용한 경우만 인스턴스화 됩니다.
template<typename T> void fn(T value, int)	// A
{
	*value = 10;
}

template<typename T> void fn(T value, double)	// B
{
}

int main()
{
//	fn(1, 3);	// fn(int, int) 즉 A사용
				// B는 인스턴스화 되지 않습니다.
				// 그런데, A에는 "*value=10" 이 있으므로 error

	fn(1, 3.3);	// B만 인스턴스화 됨.
				// A를 사용하지 않았으므로 인스턴스화 안됨.
				// "*value = 10" 은 컴파일 되지 않으므로 에러 아님
}