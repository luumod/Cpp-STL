#include <iostream>
#include<functional>
using namespace std;

//not2：对二元谓词的仿函数取反
class Greater2:public binary_function<int,int,bool>
{
public:
	//using first_argument_type = int;
	//using second_argument_type = int;
	bool operator()(const int& a,const int& b)const
	{
		return a > b;
	}
};

//not：对一元谓词的仿函数取反
class Greater1:public unary_function<int,bool>
{
public:
	//using argument_type = int;
	bool operator()(const int& val)const
	{
		return val > 10;	//大于10吗
	}
};

int main()
{
	//not2
	cout << boolalpha << Greater2()(5, 10) << endl;
	auto _My_less = not2(Greater2());		//给我们自己制作的二元谓词仿函数取反
	cout << boolalpha << "not2我做的: " << _My_less(5, 10) << endl;

	auto _less2 = not2(greater<int>());		//给标准库仿函数取反
	cout << boolalpha << "not2标准库: " << _less2(5, 10) << endl;
	//not1
	cout << boolalpha << Greater1()(50) << endl;
	auto _less1 = not1(Greater1());			//给我们自己制作的一元谓词仿函数取反
	cout << boolalpha  << "not1我做的: " << _less1(50) << endl;

	return 0;
}