// 5_friend6.cpp

// 클래스와 friend 관계
//====================
// 1. 클래스 한개와 함수 한개가 friend 관계 ( 1 : 1 )

// "Object1 클래스"  <== 친구 ==> f1()

struct Object1
{
	friend void f1();
};
void f1() {}

//==================================
// 2. 여러개 클래스 와 한개의 함수가 friend 관계 ( N : 1 )
//    Object2<int>
//    Object2<double>   <== 친구 ==>  f2()
//    Object2<short>
template<typename T>
struct Object2
{
	friend void f2();
};
void f2() {}

//================================
// 3. 한개의 클래스가 여러개의 함수와 friend( 1 : N )
//						 
// Object3	<== 친구 ==> f3(int), f3(double), f3(short) 

struct Object3
{
	template<typename U>
	friend void f3(U a);
};
template<typename U>
void f3(U a) {}

//============================================
// 4. 여러개의 클래스가 여러개의 함수와 friend( N : N )

// Object4<int> <== 친구 ==> f4(int), f4(double) ...
// Object4<int> Object<double>, Object<short> <== 친구 ==> f4(int);

template<typename T>
struct Object4
{
	template<typename U>
	friend void f4(U a);
};
template<typename U>
void f4(U a) {}

// =================================
// 5. 1 : 1로 친구가 되게 할수 없을까 ?
// Object5<int>    <===> f5(int)
// Object5<double> <===> f5(double)
// Object5<short>  <===> f5(short)

// => 클래스 템플릿의 friend 함수를 클래스 내부에 직접 만드세요
// => friend 가 있으므로 내부에 만들어도 멤버 함수는 아닙니다.
// => 이렇게 하면 1:1의 관계가 됩니다.!
template<typename T>
struct Object5
{
	friend void f5(T a)
	{

	}
};






