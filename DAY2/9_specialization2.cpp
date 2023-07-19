#include <iostream>

// STL 의 vector 구현에 대해서 생각해 봅시다.

template<typename T> class Vector
{
	T* ptr;
	std::size_t size;
public:
	Vector(std::size_t sz) : size(sz)
	{
		ptr = new T[sz];
		std::cout << "Vector<T>" << std::endl;
	}
	~Vector() { delete[] ptr; }
};

// template specialization
// => template 구현시, 특정 타입에 대해서는 내부 구현을 변경할때 사용
template<> class Vector<bool>
{
	int* ptr;
	std::size_t size;
public:
	Vector(std::size_t sz) : size(sz)
	{
		ptr = new int[(sz/32) + 1];	// 0 ~ 31 : 4바이트 사용(32bit)
									// 32 ~ 63: 8바이트 사용(64bit)

		std::cout << "Vector<bool>" << std::endl;
	}
	~Vector() { delete[] ptr; }
};



int main()
{
	Vector<int>    v1(5);	
	Vector<double> v2(5);   

	Vector<bool>   v3(100); 
}

