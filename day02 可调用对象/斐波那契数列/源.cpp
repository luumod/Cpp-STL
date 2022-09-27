#include <iostream>
using namespace std;

class Fibonacci
{
public:
	Fibonacci() :t0(0), t1(1) {}
	Fibonacci(const int& n)
		:t0(0), t1(1)
	{
		for (int i = 0; i < n; i++)
		{
			int ret = t0 + t1;
			t0 = t1;
			t1 = ret;
		}
	}

	int operator()()
	{
		int ret = t0 + t1;
		t0 = t1;
		t1 = ret;
		return t0;
	}
private:
	int t0;
	int t1;
};

struct Foo
{
	void operator()()
	{
		cout << __FUNCTION__ << endl;
	}
};

int main()
{
#if 1
	Foo a;
	//定义对象调用
	a.operator()();
	//直接通过对象调用
	a();
	//通过临时对象调用
	Foo()();
#else
	Fibonacci a(5);
	for (int i = 0; i < 5; i++)
	{
		cout << a() << " ";
	}
	cout << endl;
	Fibonacci b;
	for (int i = 0; i < 5; i++)
	{
		cout << b() << " ";
	}
#endif
	return 0;
}