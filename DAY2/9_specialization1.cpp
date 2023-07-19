#include <iostream>

// STL 의 vector 구현에 대해서 생각해 봅시다.

template<typename T> class Vector
{
	T*  ptr;
	std::size_t size;
public:
	Vector(std::size_t sz) : size(sz)
	{
		 ptr = new T[sz];
	}
	~Vector() { delete[] ptr;}
};


int main()
{
	Vector<int>    v1(5);	// new int[5] 만큼 힙을 할당해서 사용
	Vector<double> v2(5);   // new double[5] 만큼 힙 할당 

	Vector<bool>   v3(100); // bool 100개를 보관하기 위해 
							// new bool[100] 하는게 좋을까요 ???
							// true/false 100개를 보관하기 위해 100 바이트 사용 ??
							// => 100 bit 면 되지 않을까요 ?
}

