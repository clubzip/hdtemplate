template<typename T>
void f1(T a)
{
}
template<typename T>
void f2(T& a)
{
}
int main()
{
	int x[3] = { 1,2,3 };
	int y[5] = { 1,2,3, 4, 5 };

	f1(x); // f1(int* a)
	f1(y); // f1(int* a)
	f2(x); // f2(int(&a)[3])
	f2(y); // f2(int(&a)[5])
}
// 위 코드를 컴파일 했을때 함수가 몇개 생성될지 예측해 보세요
// f1 : 1 개
// f2 : 2 개

// "Decay" : 배열을 전달시 포인터로 받게 되는 현상