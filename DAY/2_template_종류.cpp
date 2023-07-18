#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <funtional>

// template 의 종류 - 8 page
// => 4가지 종류가 있습니다.

// 1. function template
// => 함수를 생성할때 사용하는 틀 - C++98 부터. 
template<typename T> T square(T a)
{
	return a * a;
}

// 2. class template
// => 클래스(구조체)를 생성할때 사용하는 틀 - C++98 지원.
template<typename T> class Vector
{
	T* buff;
};

// 3. variable template 
// => 변수(상수)를 생성하는 틀
// => C++14 부터 지원
// => 요즘에 아주 널리 사용됩니다.
template<typename T>
constexpr T pi = static_cast<T>(3.141692);

double d = pi<double>;	
float f = pi<float>;	


// 4. using template 
// => 기존 템플릿에 대한 별명을 만드는 문법
// => C++11 부터 지원
template<typename T>
using MyList = std::list<T>; // list 템플릿의 별명 MyList생성

MyList<int> s;  // std::list<int> s 와 동일


// STL priority_queue 는 템플릿 인자가 3개 입니다.
std::priority_queue<int, std::list<int>, std::allocator<int>> pq1;

// 만약 위와 같이 사용하는데, 2번째 3번째는 항상 같은 것을 사용한다면
// 아래 처럼 별명을 만드세요
template<typename T> 
using PQUEUE = std::priority_queue<T, std::list<T>, std::allocator<T>>;

PQUEUE<int> pq2;