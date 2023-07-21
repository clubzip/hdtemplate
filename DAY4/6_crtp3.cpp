#include <iostream>

template<typename T>
class Window
{
public:
	void event_loop()	// void event_loop(Window* this)
	{
		// Click();		//	this->Click() 으로 변경됩니다			

		// this를 직접 사용하지 말고, 파생 클래스 타입으로 캐스팅해서
		// 멤버함수를 호출하면
		// 가상함수가 아니라도, 가상함수 효과를 볼수 있습니다.
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
