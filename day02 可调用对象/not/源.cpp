#include <iostream>
#include<functional>
using namespace std;

//not2���Զ�Ԫν�ʵķº���ȡ��
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

//not����һԪν�ʵķº���ȡ��
class Greater1:public unary_function<int,bool>
{
public:
	//using argument_type = int;
	bool operator()(const int& val)const
	{
		return val > 10;	//����10��
	}
};

int main()
{
	//not2
	cout << boolalpha << Greater2()(5, 10) << endl;
	auto _My_less = not2(Greater2());		//�������Լ������Ķ�Ԫν�ʷº���ȡ��
	cout << boolalpha << "not2������: " << _My_less(5, 10) << endl;

	auto _less2 = not2(greater<int>());		//����׼��º���ȡ��
	cout << boolalpha << "not2��׼��: " << _less2(5, 10) << endl;
	//not1
	cout << boolalpha << Greater1()(50) << endl;
	auto _less1 = not1(Greater1());			//�������Լ�������һԪν�ʷº���ȡ��
	cout << boolalpha  << "not1������: " << _less1(50) << endl;

	return 0;
}