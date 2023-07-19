// 92 page

// 템플릿 파라미터는 3가지 종류가 있습니다.
// 1. type
// 2. non-type
// 3. template

template<typename T> class list 
{
};
// list : template
	
template<typename T,					// type paramter			
	     int N,							// non-type parameter (정수)
	     template<typename> class C>	// template parameter
class Object							// => 흔히 "template template parameter" 라고도합니다.
{
//	C c; // error. C 는 타입이 아닌 템플릿
	C<T> c; // ok. C 는 인자가 한개인 템플릿 이므로 C<T> 는 타입
};

int main()
{
//	list      s1;	// list      는 template
//	list<int> s2;	// list<int> 는 type

//	Object<int , 5 , list<int> > obj; // error
									  // list<int> 는 타입이지 template 이 아닙니다
	Object<int, 5, list > obj; // ok.. list 는 타입이 아니라 template!
}
