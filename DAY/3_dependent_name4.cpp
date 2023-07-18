template<typename T>
struct Object
{
	template<typename U>
	static void mf() {	}
};
// Object<double> 인 경우에는 다른 구현 제공. 
template<>
struct Object<double>
{
	static constexpr double mf = 3.4;
};

int main()
{
	// Object<T> 에서 T가 어떤 타입이라도
	// 결국 mf 는 함수 템플릿 아닌가요 ??
	// 왜?? 컴파일러가 mf 를 알수 없나요 ???
	// => template 특수화 문법 때문에..
	Object<int>::mf<int>();
	double d = Object<double>::mf;

	// T가 템플릿 인자일때
//	Object<T>::mf    // T에 따라 mf 는 함수 템플릿 일수도 있고
					 // 변수(상수)일수도 있습니다.
}
// 결론 : typename 은 반드시 알아야 합니다. 너무 많이 사용됩니다.
//       template 은 많이 나오지는 않지만, 왜 필요 한지 알아두세요