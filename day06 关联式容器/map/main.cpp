#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <xtree>
using namespace std;

int main()
{
#if 0
	//​multiset与set的区别：set支持唯一键值，每个元素值只能出现一次；而multiset中同一值可以出现多次。
	//set<int> a{ 1,1,2,2,3,3,4,5,6 };
	set<int> a{ 56,89,45,12,32,65,999,1111};
	multiset<int> b{ 1,1,2,2,3,3,4,5,6 };
	cout << "set容器的删除永远返回：" << a.erase(1) << endl;
	cout << "multiset容器的删除可以有多个：" << b.erase(1) << endl;
	/*
	set：		1 2 3 4 5 6
	multiset：	1 1 2 2 3 3 4 5 6
	*/
	cout << a.size() << endl;
	cout << boolalpha << a.empty() << endl;
	auto it=a.key_comp();
	for (auto& x1 : a)
	{
		cout << x1 << " ";
	}
	cout << endl;
	for (auto& x2 : b)
	{
		cout << x2 << " ";
	}
	cout << endl;
#else
	map <string, int> a{ {"喜羊羊",2},{"喜羊羊",2},{"虎太郎",3},{"懒洋洋",10} };
	multimap <string, int> a1{ {"喜羊羊",2},{"喜羊羊",2},{"虎太郎",3},{"懒洋洋",10} };

	
	////通过pair来插入键值对
	//auto it=a.insert(pair<string, int>("熊大", 15));
	//cout <<"插入成功了吗？"<<boolalpha<<it.second<<"\t"<< it.first->first << ": " << it.first->second << endl;

	////通过make_pair来插入键值对
	//it=a.insert(make_pair<string, int>("小灰灰", 55));
	//cout << "插入成功了吗？" << boolalpha << it.second << "\t" << it.first->first << ": " << it.first->second << endl;


	////通过value_type来插入
	//it=a.insert(map<string, int>::value_type("熊二", 66));
	//cout << "插入成功了吗？" << boolalpha << it.second << "\t" << it.first->first << ": " << it.first->second << endl;


	////通过数组方式插入
	//a["美羊羊"] = 666;
	//a["茶人"] = 999;

	///*
	//删除元素
	//*/
	////删除关键字对应的键值对
	//a.erase("喜羊羊");		//返回size_t 即删除的个数
	////删除区间
	//auto it1 = ++a.begin();
	//++it1;
	//++it1;
	//a.erase(a.begin(),it1);


	//pair<const string, int> aPoint;
	for (auto& x : a)
	{
		cout << x.first << ":" << x.second << endl;
	}
	cout << endl;
	for (auto& x : a1)
	{
		cout << x.first << ":" << x.second << endl;
	}
#endif
	return 0;
}