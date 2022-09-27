#include <iostream>
#include <map>
#include <functional>
using namespace std;

int add(int a, int b)
{
	return a + b;
}

class Foo
{
public:
	mutable int a, b;
	Foo() = default;
	Foo(const int& a, const int& b) :a(a), b(b){}
	void Class()
	{
		cout << __FUNCTION__ << endl;
	}
	void operator()(int a, int b)
	{
		cout << __FUNCTION__ << ": " << a * b << endl;
	}
};

int main()
{
	//��װ��ͨ����
	function<int(int, int)> F1{add};
	cout << F1(5, 10) << endl;

	//��װ��Ա����������Ҫ����bind��
	Foo a;
	function<void(int,int)> F2_1 = bind(&Foo::operator(),Foo(), placeholders::_1, placeholders::_2);
	function<void()> F2_2 = bind(&Foo::Class, Foo());
	F2_1(5,122);
	F2_2();

	//��װ�������󣨷º�����
	function<void(int,int)> F3 = bind(Foo(), placeholders::_1, placeholders::_2);
	F3(50, 40);

	//function͵ȡ��׼�⺯��
	function<bool(int, int)> My_greater = bind(greater<int>(), placeholders::_1, placeholders::_2);
	cout << boolalpha << My_greater(50, 10) << endl;
	function<bool(int)> My_less = bind(less<int>(), placeholders::_1, 20);
	cout << boolalpha << My_less(10) << endl;


	//��װlambda���ʽ
	function<void(const int&,const int&)> F4 = bind([](const int& a, const int& b) {cout <<__FUNCTION__<<" :: " << a << ": " << b << endl; }, placeholders::_1, placeholders::_2);
	F4(669, 999);

	map<char, int> m{ {'c',5},{'a',10}};
	string s = "ACBDAD";

	cout << s.find('A') << endl;
	return 0;
}