template<typename T>
struct Object
{
	using type = T;
	template<typename U>
	static void mf() {	}
};

template<typename T>
void foo()
{
	// 1. typename 
	Object<int>::type t1; // ok.  int t1
						  // T 를 사용한적은 없음..
						  // type 은 dependent name 아님
						  // typename 필요 없음.
							
	// 아래 2줄은 모두 T에 의존합니다. dependent name 입니다.
	// typename 필요
//	typename T::type t;			// 문법상은 맞지만,
								// main 에서 T=int 를 전달하므로
								// int::type t 라서 인스턴스화 에러

	typename Object<T>::type t2;// Object<int>::type t2 이므로
								// 결국 int t2;
	
	// 2. template
	Object<int>::mf<double>();	// ok. 
								// T 를 사용한 적이 없음..
								// dependent name 아님.

//	Object<T>::mf<double>(); // mf 는 dependent name!!
							 // 하지만 mf 는 타입의 이름은 아님
							 // => typename 필요 없음.
							 // 그런데, "mf<" 에서 "<" 의 의미파악이 안됨
							//  => 그래서 mf 가 템플릿 이라고 알려주어야 함

	Object<T>::template mf<double>(); // ok.
						// 클래스 템플릿의 멤버 함수템플릿을 T에 의존해서
						// 호출하는 모양!

	//------------------------
	Object<int> o1; // o1은 T에 의존하지 않습니다.
	Object<T> o2;   // o2은 T에 의존합니다. T에 따라 달라 질수 있습니다.

	// o1, o2 를 사용해서 mf() 호출하는 코드 만들어 보세요
	// mf 의 템플릿 인자를 <int> 로 해서 전달해 보세요
	o1.mf<int>();
	
//	o2.mf<int>(); // ?? o2 자체가 dependent name 입니다.
					// mf 의 의미는 T에 따라 달라 질수 있습니다.
	o2.template mf<int>();

}

int main()
{
	foo<int>();
}