
// 53page
template<typename T>
class Object
{
public:
	// 핵심 1. Object 는 "class template" 입니다.
	// 핵심 2. mf1 은 "일반 멤버 함수" 입니다. template 아닙닏니다.
	//         mf1 의 인자 타입은 항상 int 입니다.
	void mf1(int n) {}

	// 핵심 3. mf2 는 "함수 템플릿" 이 아닙니다. <== 중요!!
	//        "class template" 의 "일반 멤버 함수" 입니다.
	//         Object<int> obj1; 이순간 mf2의 인자는 int로 결정.
	//		   즉, 함수를 호출시 타입이 결정되는 것이 아니라, 객체 생성시 결정
	void mf2(T   n) {}

	// 핵심 4. mf3 은 "함수 템플릿" 입니다.
	// => "class template 의 member function template" 이라고 부릅니다.
	// => mf3(3)   => mf3(int) 생성
	// => mf3(3.3) => mf3(double) 생성
	template<typename U>
	void mf3(U n) {}
};

int main()
{
	Object<int> obj1;		// mf2(int)로 결정
	Object<double> obj2;	// mf2(double)로 결정

	// mf1의 인자는 항상 int 타입입니다.
	obj1.mf1(3);	
	obj2.mf1(3); 

	//
	obj1.mf2(3);	// 
	obj1.mf2(3.4);	// mf2(double)를 생성한것이 아닙니다.
					// mf2(int) 버전에 3.4 를 전달한것
	
					
	// mf3 은 함수 템플릿 이므로 "인자의 타입"에 따라 "함수가 생성" 됩니다.
	obj1.mf3(3);	// mf3(int) 생성
	obj1.mf3(3.4);	// mf3(double) 생성		
}
