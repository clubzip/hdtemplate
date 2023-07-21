#include <iostream>


template<typename T>
class Window
{
public:
	// 수십~수백개의 Window 관련 멤버 함수들
	void show_window() {}
	void move_window() {}
	void set_top_most() {}
	
	// 그리고, 수백개의 이벤트 처리 함수들
	void Keydown() {}
	void Activate() {}

	void event_loop()
	{
		static_cast<T*>(this)->Click();
	}
	void Click() { std::cout << "Window Click" << std::endl; }
};



class MainWindow : public Window<MainWindow>
{
public:
	void Click() { std::cout << "MainWindow Click" << std::endl; }
};
int main()
{
	MainWindow w;
	w.event_loop();
}
