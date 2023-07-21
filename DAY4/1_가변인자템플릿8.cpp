#include <iostream>

// C++ 창시자가
// C++11 발표시, 가변 인자 템플릿 예제로, 
// printf 를 다시 만들어서 소개 합니다.

// 아래코드와 유사합니다.

// 아래 함수는 "재귀의 종료" 를 위한 버전
void safe_printf(const char* s)
{
    while (*s) {
        if (*s == '%') {
            if (*(s + 1) == '%') {
                ++s;
            }
            else {
                throw "invalid format string: missing arguments";
            }
        }
        std::cout << *s++;
    }
}

template<typename T, typename... Args>
void safe_printf(const char* s, const T& value, Args... args)
{
    while (*s) {
        if (*s == '%') {
            if (*(s + 1) == '%') {
                ++s;
            }
            else {
                std::cout << value; // 이름있는 인자로 받은것 출력

                safe_printf(s + 1, args...); // 재귀 호출 유사한 기술 사용
                return;
            }
        }
        std::cout << *s++;
    }
    throw "extra arguments provided to printf";
}
int main()
{
    try
    {
        safe_printf("%, %\n", 1, 2); // ok
//      safe_printf("%, %\n", 1);    // 인자 갯수 부족 => 예외 발생
//      safe_printf("%, %\n", 1, 2, 3);// 인자 갯수 초과 => 예외 발생
    }
    catch (const char* e)
    {
        std::cout << e << std::endl;
    }
}

// 가변인자 템플릿 학습용으로만 사용하고
// 실제 사용하지 마세요.. 함수가 여러개 생성되어서 코드메모리 증가합니다.