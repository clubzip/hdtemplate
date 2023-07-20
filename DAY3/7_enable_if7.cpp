#include <iostream>
#include <string>

// enable_if 기술
// 일반 함수 : 보통 반환 타입 위치에 사용합니다.
//            인자에 사용해도 되지만, 코드가 복잡해 보입니다.

// 생성자 : 반환 타입이 없습니다.
//          그래서, 템플릿 인자에 많이 사용합니다.



class Animal {};
class Dog : public Animal {};

template<typename T> class smart_ptr
{
	T* obj = nullptr;
public:
	explicit smart_ptr(T* p) : obj(p) {}

	// enable_if 를 사용해서
	// U* => T* 로 복사 될수 없다면
	// "템플릿 자체를 사용하지 못하게 하면 에러 메세지가 보기 좋습니다."

	// 함수 생성후 에러가 아닌, 함수 생성자체가 될수 없도록

//	template<typename U,
//	         typename K = std::enable_if_t<조건> > // 조건을 만족하면 디폴트값 void
												   // 만족하지 못하면 치환 실패. 사용안함
	// 6번소스와 이코드(7번)의 에러 메시지 차이점을 확인해 보세요
	template<typename U,
		typename K = std::enable_if_t< std::is_convertible_v<U*, T*> > > 

	smart_ptr(const smart_ptr<U>& sp) : obj(sp.obj) {}

	template<typename> friend class smart_ptr;
};
int main()
{
	smart_ptr<Dog>    p1(new Dog);
	smart_ptr<Animal> p2 = p1;	

	smart_ptr<int> p3 = p1;		// error. Dog* => int* 로 복사 될수 없습니다.						   
}
// github.com/aosp-mirror  에서
// platform system core    레포지토리 선택하세요
// libutils/include/utils/typehelpers.h  열어 보세요
// copy_type 함수 찾아 보세요.. 

