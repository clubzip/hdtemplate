// QA.cpp

template<typename T, int N>
struct Object 
{
	T buff[N]; 
};

int main()
{
	const int c = 10;
	
	Object<int, c> obj1;	// 여기서 c를 사용하고
	
	// 위 한줄을 컴파일 하면 컴파일러는 아래 클래스를 생성합니다.
	/*
	// => 핵심 생성된 코드에 "c" 라는 이름을 사용하는 것이 아니라 
	// => 컴파일 시점에 c가 가진 값을 가지고 코드를 생성합니다.
	struct Object
	{
		int buff[10];
	};
	*/

	// 다양한 방법으로 강제로 c의 값을 변경하면 어떻게 되나요 ?
	*(const_cast<int*>(&c)) = 20;
				// => 물론, 이렇게 const 를 강제로 변경하는 것은
				// => "undefined" 입니다.
}
