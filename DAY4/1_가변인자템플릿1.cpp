// 175 page

// template<typename T>  // Ÿ�����ڸ� �Ѱ��� ���� ����

template<typename ... Types> // C++11 ���� ���� ���ø�
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

