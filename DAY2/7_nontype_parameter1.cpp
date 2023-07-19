enum       Color1 {red, blue, green};
enum class Color2 {red, blue, green};

void foo(int a) {}

// 템플릿 파라미터로 "type", "template" 외에도 아래와 같은 것들을 사용가능합니다.
// => "현재는 정수 인자" 정도를 널리 사용하고 있습니다.
// => 아래와 같이 다양하게 사용가능하고 모두 "non-type parameter" 라고 합니다.
// => 그런데, 실전에서는 "정수(int)" 정도만 널리 사용됩니다

template<int N, 	// 정수
		 double d,	// 실수는 "C++20" 부터만 가능합니다.
		 Color1 C1, // enum
		 Color2 C2, // C++11 의 새로운 enum
		 int* P, 	// 포인터,  단, 지역변수 주소는 안되고, 전역또는  static 만가능
		 void(*FP)(int)> // 함수 포인터 가능. 
class NTTP
{
};

int main()
{
	int n = 10;
	static int s = 0;

	NTTP<10, 3.4, Color1::red, Color2::red, &s, &foo > t1; // ok
//	NTTP<10, 3.4, Color1::red, Color2::red, &n, &foo > t2; // error
															// &n 에서 n은 지역변수
}
