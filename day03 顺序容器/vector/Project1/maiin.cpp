#include <iostream>
#include <vector>
using namespace std;

int main()
{
	/*
	构造方式
	*/
	vector<int> a{ 1,2,3,4,5,6 };	//聚合初始化
	const vector<int> b(5);	//指定大小
	vector<int> c(10, 0);	//指定大小并且初始化为0
	vector<int> d(a.begin(), a.end());	//复制另一个容器的数据
	vector<int> e(a);	
	vector<int> f(b);
	
	/*
	访问元素
	*/
	cout << a[0] << endl;
	cout << a.at(5) << endl;
	cout << a.front() << endl;
	cout << a.back() << endl;
	auto p = a.data();	//返回指向数组第一个元素的指针

	/*
	容量相关
	*/
	cout << a.size() << endl;		//获取元素个数
	cout << a.max_size() << endl;	//可以存储的最大元素个数
	cout << a.capacity() << endl;	//获取当前容量个数，自动扩容
	a.reserve(100);		//增大容量到100
	cout << a.capacity() << endl;	//打印：100
	a.resize(4);				//调整容量为4，多余的元素会被消除
	a.resize(10, -99);	//调整容量为10，用-99做填充
	a.clear();						//清空容器元素个数，但是它的总的容量不变
	cout << a.size() << endl;		//打印：0   capacity：100
	cout << a.empty() << endl;	//判断空容器
	a.shrink_to_fit();
	cout << a.capacity() << endl;	//将容器减小容量到适当的大小，当前元素个数0 即减小到0

	/*
	容器的修改
	*/
	vector<int> temp{ 9,8,7,6,5,4 };
	a.push_back(10);			//尾部插入元素10
	a.pop_back();					//尾删
	a.emplace(a.end(),10);//emplace常用于类对象的构造，在a的末尾插入元素10
	a.emplace_back(55);			//在尾部构造一个元素55
	a.assign(50, -99);	//重新设置大小容器大小为50，并且用-99填充
	a.assign(b.begin(), b.end());	//以相同的顺序复制b容器的数据

	a.insert(a.begin(), 555);	//在容器的开始位置，插入一个元素555
	a.insert(a.begin(), 10, 999);	//在a的begin处，插入10个999
	a.insert(a.end(), temp.begin(), temp.end());	//在a的末尾处插入temp的指定范围的元素
	a.insert(a.end(), { 1,2,3 });	//在容器的末尾插入一个聚合列表

	a.erase(a.begin());		//删除容器的begin处的元素
	a.erase(a.begin(), a.begin() + 9);//删除指定范围区间的元素
	a.swap(temp);			//交换两个vector的内容
	vector<int> null;
	a.swap(null);			//清空容器
	for (auto& x : a)
	{
		cout << x << " ";
	}
	
	return 0;
}