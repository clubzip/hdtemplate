template<typename T>
struct Object
{
	template<typename U>
	static void mf() {	}
};
int main()
{
	// Object<T> 에서 T가 어떤 타입이라도
	// 결국 mf 는 함수 템플릿 아닌가요 ??
	// 왜?? 컴파일러가 mf 를 알수 없나요 ???
	// => template 특수화 문법 때문에..
	Object<int>::mf<int>();
}