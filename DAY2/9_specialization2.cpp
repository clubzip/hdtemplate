#include <iostream>

// STL �� vector ������ ���ؼ� ������ ���ô�.

// "primary template"
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

// template specialization(Ư��ȭ, ����ȭ)
// => template ������, Ư�� Ÿ�Կ� ���ؼ��� ���� ������ �����Ҷ� ���
// => Ÿ���� �����ϰ� ������ ���. 
// => <> �ȿ� typename �� �����ϴ�.
template<> class Vector<bool>
{
	int* ptr;
	std::size_t size;
public:
	Vector(std::size_t sz) : size(sz)
	{
		ptr = new int[(sz/32) + 1];	// 0 ~ 31 : 4����Ʈ ���(32bit)
									// 32 ~ 63: 8����Ʈ ���(64bit)

		std::cout << "Vector<bool>" << std::endl;
	}
	~Vector() { delete[] ptr; }
};


// T�� ���� Ÿ���� ������ �϶�
// template partial specialization(�κ� Ư��ȭ, �κ� ����ȭ)
// => <> �ȿ� typename �� �ֽ��ϴ�.
template<typename T> class Vector<T*>
{
	T* ptr;
	std::size_t size;
public:
	Vector(std::size_t sz) : size(sz)
	{
		ptr = new T[sz];
		std::cout << "Vector<T*>" << std::endl;
	}
	~Vector() { delete[] ptr; }
};

int main()
{
	Vector<int>    v1(5);	
	Vector<double> v2(5);   

	Vector<bool>   v3(100); 
	Vector<int*>   v4(5);
}

