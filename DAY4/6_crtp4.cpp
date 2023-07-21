#include <iostream>

// 아래 처럼 만들면 10개의 파생 클래스를 만들게 될때
// 10개의 기반 클래스가 모두 다른 클래스 입니다.
// 멤버 함수가 20개 라면 (20 * 10개 클래스 => 200개 함수 생성)

// class W1 : public Window<W1>{}
// class W2 : public Window<W2>{}
// class W3 : public Window<W3>{}

// std::vector<기반클래스???*> v; // 기반 클래스가 모두 다릅니다.!!


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
class ImageView : public Window<ImageView>
{
public:
	void Click() { std::cout << "MainWindow Click" << std::endl; }
};


int main()
{
	MainWindow w;
	w.event_loop();
}
