// 32 page, lazy instantiation

// 아래 코드가 왜 에러인지 생각해 보세요
class Object
{
	int value;
public:
	void mf()
	{
		*value = 10;	// value 는 int 타입이므로
						// *value 연산을 할수 없습니다.
	}
};

int main()
{
	Object obj;
}
