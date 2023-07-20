// printv 복사 - integral_constant3.cpp 복사

#include <iostream>
#include <type_traits> 

// 정리
// SFINAE : template 을 사용해서 함수 만들때 
//	        치환실패(함수반환타입, 인자 모양등을 만들때 실패 한것)
//          라면 에러가 아닌 후보에서 제외 된다는 
//          C++ 문법적 규칙!!!!

// enable_if : 조건을 만족하지 못하면 "치환 실패(::type 없음)" 가 되도록하기 위해
//			   만든 도구..

// enable_if 외에도 SFINAE 를 활용하는 기술은 아주 많습니다.




// std::enable_if 를 사용한 printv 만들기

template<typename T>
std::enable_if_t< std::is_pointer_v<T> >    // 반환 타입이 void 라면 생략가능
printv(const T& value)
{
	std::cout << "pointer version : " << value << " : " << *value << std::endl;
}

template<typename T>
std::enable_if_t< !std::is_pointer_v<T> >
printv(const T& value)
{
	std::cout << "not pointer version : " << value << std::endl;
}


int main()
{
	int n = 10;
	printv(&n);
	printv(n);

}

