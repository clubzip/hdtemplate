// 175 page

// template<typename T>  // 타입인자를 한개만 전달 가능

template<typename ... Types> // C++11 가변 인자 템플릿
class tuple 
{
};

int main()
{ 
	tuple<> t0;					 // Types : 
	tuple<int> t1;				 // Types : int
	tuple<int, double> t2;		 // Types : int, double
	tuple<int, double, char> t3; // Types : int, double, char
}

