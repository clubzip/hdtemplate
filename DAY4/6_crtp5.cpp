#include <iostream>

// Thin Template 기술 - C++ IDioms 사이트에서 참고해 보세요
// 
// => 클래스 템플릿 안에.. 템플릿 인자 T를 사용하지 않은 멤버가 있다면
// => 템플릿이 아닌 기반 클래스를 만들어서 제공합니다.

class Window
{
	int handle;
	int color;  
public:
	// 수십~수백개의 Window 관련 멤버 함수들
	void show_window() {}
	void move_window() {}
	void set_top_most() {}

	// 그리고, 수백개의 이벤트 처리 함수들
	void Keydown() {}
	void Activate() {}
	void Click() { std::cout << "Window Click" << std::endl; }
};
template<typename T>
class EventWindow : public Window
{
public:
	void event_loop()
	{
		static_cast<T*>(this)->Click();
	}
};

class MainWindow : public EventWindow<MainWindow>
{
public:
	void Click() { std::cout << "MainWindow Click" << std::endl; }
};
class ImageView : public EventWindow<ImageView>
{
public:
	void Click() { std::cout << "MainWindow Click" << std::endl; }
};


int main()
{
	MainWindow w;
	w.event_loop();
}
