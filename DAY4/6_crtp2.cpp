#include <iostream>

// 라이브러리 내부 클래스
class Window
{
public:
	// 발생된 이벤트를 조사해서 약속된 함수를 호출하는 기능을 가진 함수
	void event_loop()	// void event_loop(Window* this)
	{			
		Click();		//	this->Click() 으로 변경됩니다			
	}
	//void Click()     { std::cout << "Window Click" << std::endl; }
	virtual void Click() { std::cout << "Window Click" << std::endl; }
};


// 아래 클래스가 라이브러리 사용자 코드.
// => Window 에서 파생된 클래스 만들어서, 약속된 함수 재정의!
class MainWindow : public Window 
{
public:
	void Click() { std::cout << "MainWindow Click" << std::endl; }
};
int main()
{
	MainWindow w;
	w.event_loop();
}
