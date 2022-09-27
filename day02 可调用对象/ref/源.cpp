#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

class Foo
{
public:
	mutable int number = 0;
	void operator()()const
	{
		cout << number << endl;
		number++;
	}
};

class Ani
{
public:
	int number = 0;
	void printDog()
	{
		cout << __FUNCTION__ << " 汪汪汪: " << number++ << endl;
	}
	void printCat()
	{
		cout << __FUNCTION__ << " 喵喵喵: " << number++ << endl;
	}
	void Anis(int a,int b,int c)
	{
		cout << a << " " << b << " " << c << endl;
	}
};

//测试最终示例
class Num
{
public:
	Num(const int& data)
		:val(data)
	{}
	void travel()
	{
		cout << val << " ";
	}

private:
	int val;
};

int main()
{
	Foo f;
	auto fun1 = bind(cref(f));
	fun1();
	fun1();
	fun1();
	fun1();

	cout << endl;
	cout << endl;
	cout << endl;

#if 0
	Ani d;
	auto func1 = mem_fun(&Ani::printDog);	//传递成员函数指针，
	func1(&d);		//把成员函数转换为函数对象，使用可调用对象调用成员函数
	d.printDog();

	Ani c;
	auto fun2 = mem_fun_ref(&Ani::printCat);	//传递成员函数指针
	fun2(c);
	c.printCat();

	Ani all;
	auto fun3 = mem_fn(&Ani::Anis);
	fun3(Ani(), 1, 2, 3);
	fun3(&all, 1, 2, 3);
	fun3(all, 1, 2, 3);
#endif

	//测试
	vector<Num> a;
	for (int i = 0; i < 10; ++i)
	{
		a.emplace_back(i);
	}

	//将成员函数转变为函数对象
	for_each(a.begin(), a.end(),mem_fn(&Num::travel));
	cout << endl;
	for_each(a.begin(), a.end(), mem_fun_ref(&Num::travel));

	cout << endl;
	cout << endl;

	vector<Num*> b;
	for (int i = 0; i < 10; ++i)
	{
		b.emplace_back(new Num(i * 2));
	}
	for_each(b.begin(), b.end(), mem_fun(&Num::travel));

	return 0;
}


