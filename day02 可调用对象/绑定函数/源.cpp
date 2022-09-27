#include <iostream>
#include <string>
#include <functional>
using namespace std;

void show(int number, const string& name)
{
	cout << number << " : " << name << endl;
}
struct Plus
{
	int plus(int a, int b)
	{
		return a + b;
	}
};

struct Foo
{
	int operator()(int a,int b)
	{
		return a * b;
	}
};

int main()
{
	//顺序绑定参数
	auto bind_show=bind(show, placeholders::_1, placeholders::_2);
	bind_show(555, "yyyy");

	//更改绑定位置
	auto bind_show2 = bind(show, placeholders::_2, placeholders::_1);
	bind_show2("ylh", 666);
	//绑定固定参数
	auto bind_show3 = bind(show, 888, placeholders::_1);
	bind_show3("moren");
	//完全绑定
	auto bind_show4 = bind(show, 666, "oooo");
	bind_show4();

	//绑定成员函数
	Plus a;
	auto bind_func1 = bind(&Plus::plus,Plus(), placeholders::_1, placeholders::_2);	//绑定匿名对象的成员函数，引用
	auto bind_func2 = bind(&Plus::plus, a, placeholders::_1, placeholders::_2);		//绑定成员函数的引用
	auto bind_func3 = bind(&Plus::plus,&a, placeholders::_1, placeholders::_2);		//绑定成员函数的指针
	cout << bind_func1(6, 11) << endl;
	cout << bind_func2(5, 10) << endl;
	cout << bind_func3(7, 20) << endl;

	//绑定函数对象
	Foo b;
	auto bind_FuncObject1 = bind(Foo(), placeholders::_1, placeholders::_2);
	auto bind_FuncObject2 = bind(b, placeholders::_1, placeholders::_2);

	cout << bind_FuncObject1(6, 20) << endl;
	cout << bind_FuncObject2(6, 20) << endl;


	//绑定lambda表达式
	auto bind_lambda = bind([](const int& a, const int& b) {cout << a << " : " << b; }, placeholders::_1, placeholders::_2);
	bind_lambda(1, 2);

	return 0;
}