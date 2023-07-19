template<typename T>
class Object
{
public:
	void mf1(int n);	
	void mf2(T   n);
	template<typename U>
	void mf3(U n);
};

// mf1, mf2, mf3 외부 구현 만들어 보세요.
template<typename T>
void Object<T>::mf1(int n) 
{
}

template<typename T>
void Object<T>::mf2(T n)
{
}

//template<typename T, typename U> // 이렇게 하면 Object 클래스의 템플릿 인자가 2개 라는 의미
template<typename T> template<typename U> // 이렇게 해야 합니다.
void Object<T>::mf3(U n)
{
	// 이 표기법이 "class template 의 member function template" 을 외부 구현하는 모양입니다.
	// 
	// github.com/aosp-mirror  이 "안드로이드 소스 코드" 입니다.
	// platform system core 레포지토리 선택후
	// libutils/include/utils/strongpointer.h 열어 보세요 => 안드로이드 스마트 포인터 소스
	// "sp"
}

int main()
{

}
