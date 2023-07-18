
// 이 코드는 결국 Object<int> 로 사용하므로
// 1번.cpp 코드와 동일합니다.. 그런데.. 왜 A 가 에러가 아닐까요 ?
template<typename T>
class Object
{
	T value;
public:
	void mf()
	{
		*value = 10; // A	
	}
};

int main()
{
	Object<int> obj;
	obj.mf();	// 이렇게 사용하는 코드가 있어야만
				// mf 가 실제 class 를 만들때 포함됩니다. 
}

// 위 코드 처럼, 사용하는 경우에만 인스턴스화에 포함되는 것을
// "lazy instantiation(지연된 인스턴스화)" 라고 합니다.