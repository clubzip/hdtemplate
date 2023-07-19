#include <iostream>

// STL �� vector ������ ���ؼ� ������ ���ô�.

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
	Vector<int>    v1(5);	// new int[5] ��ŭ ���� �Ҵ��ؼ� ���
	Vector<double> v2(5);   // new double[5] ��ŭ �� �Ҵ� 

	Vector<bool>   v3(100); // bool 100���� �����ϱ� ���� 
							// new bool[100] �ϴ°� ������� ???
							// true/false 100���� �����ϱ� ���� 100 ����Ʈ ��� ??
							// => 100 bit �� ���� ������� ?
}

