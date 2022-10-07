#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <list>
#include <functional>
#include <forward_list>
#include <algorithm>
using namespace std;

class Foo
{
public:
	static int cnt;
	int operator()()
	{
		return ++cnt;
	}
};
int Foo::cnt = 1;
int main()
{
#if 0
	/*
	all_of:
		如果pred对范围[第一个和最后一个]中的所有元素都返回true，或者范围为空，则返回true，否则返回false
	*/

	vector<int> a{ 1,3,5,7,9,11 };
	//判断所有的元素为奇数
	auto it = all_of(a.begin(), a.end(), [](const int& data) {return data % 2; });
	cout << boolalpha << it << endl;
#elif 0
	/*
	any_of:
		如果pred对范围[第一个和最后一个]中的任意元素返回true，或者范围为空，则返回true，否则返回false
	*/

	vector<int> a{ 2,4,5,8,10,12 };
	//判断容器存在奇数元素
	auto it = any_of(a.begin(), a.end(), [](const int& data) {return data % 2; });
	cout << boolalpha << it << endl;
#elif 0
	/*
	binary_search：
		二分查找
	*/
	vector<int> a{ 1,2,3,4,5,6,7,8,9,10 };
	//查找元素12：false
	cout << boolalpha << binary_search(a.begin(), a.end(), 12) << endl;
#elif 0
	/*
	copy:
		拷贝元素 Copies the elements in the range [first,last) into the range beginning at result.
	*/
	deque<int> a{ 1,2,3,4,5,6 };
	deque<int> b(a.size()); //你需要先给目标容器扩充至合适的容量
	//拷贝容器内的元素，注意：返回目标的end迭代器
	auto it = copy(a.begin(), a.end(), b.begin());
	for (auto& x : b)
	{
		cout << x << " ";
	}
#elif 0
	/*
	copy_backward:
		倒着拷贝容器的元素
	*/
	deque<int> a{ 1,2,3,4,5,6 };
	deque<int> b(a.size()); //你需要先给目标容器扩充至合适的容量
	//倒着拷贝容器内的元素，返回第一个元素的迭代器，注意要传给dst一个end的开始位置，因为它是从后往前复制的，但是他的元素顺序不变
	auto it = copy_backward(a.begin(), a.end(), b.end());
	for (auto& x : b)
	{
		cout << x << " ";
	}
#elif 0
	/*
	copy_if:
		Copies the elements in the range [first,last) for which pred returns true to the range beginning at result.
	*/
	list<int> a{ 1,2,3,4,5,6 };
	list<int> Dst(a.size());
	//如果a的元素存在奇数，则把奇数复制给Dst容器，返回指向的最后一个元素迭代器
	auto it = copy_if(a.begin(), a.end(), Dst.begin(), [](const int& data) {return data % 2; });
	//重新设置目标容器的大小
	Dst.resize(distance(Dst.begin(), it));
	for (auto& x : Dst)
	{
		cout << x << " ";
	}
#elif 0
	/*
	copy_n:
		Copies the first n elements from the range beginning at first into the range beginning at result.
	The function returns an iterator to the end of the destination range (which points to one past the last element copied).
	*/
	vector<int> a{ 9,8,7,6,5,4,3,2,1 };
	deque<int> Dst(a.size());
	size_t pos = 5;	//越界报错
	//拷贝a容器的前pos个元素到目标容器
	auto it = copy_n(a.begin(), pos, Dst.begin());
	Dst.resize(distance(Dst.begin(), it));
	for (auto& x : Dst)
	{
		cout << x << " ";
	}
#elif 0
	/*
	count:
		统计等于val的元素的个数，自定义类型需要重载operator==运算符
	*/
	vector<int> a{ 9,8,7,6,5,5,5,5,5,3,2,1 };
	//拷贝a容器的前pos个元素到目标容器
	cout << count(a.cbegin(), a.cend(), 5) << endl;
#elif 0
	/*
	count_if:
		如果符合条件，则统计元素
	*/
	vector<int> a{ 1,2,3,4,5,6 };
	//统计等于5的元素的个数
	cout << count_if(a.begin(), a.end(), bind(equal_to<int>(), placeholders::_1, 5)) << endl;
#endif

#if 0
	/*
	equal:
		比较两个序列的元素是否相等
	*/
	vector<int> a{ 1,2,3,4,5,6 };
	vector<int> b{ 1,2,3,5,6,7 };
	//The comparison includes up to as many elements of this sequence as those in the range [first1,last1). 两个容器的元素个数必须相等
	cout << boolalpha << equal(a.begin(), a.end(), b.begin()) << endl;
	//通过此调用比较容器的一部分是否相等
	cout << boolalpha << equal(a.begin(), a.begin() + 3, b.begin(), b.begin() + 3, [](const int& a1, const int& a2) {return a1 == a2; }) << endl;
#elif 0
	/*
	equal_range

	*/
	vector<int> a{ 1,2,3,4,5,6,7,8,9 };
	deque<int> b{ 3,4,5,6,6,6,7,8,9,10 };
	//pair类型作为返回值，first指向其符合的第一个元素的下标位置，second指向符合的最后一个元素的下一个位置，注意类型不同，pair类型也不同
	pair<vector<int>::iterator, vector<int>::iterator> dst;
	pair<deque<int>::iterator, deque<int>::iterator> dstDeque;
	//下标： 3 ----- 7
	dstDeque = equal_range(b.begin(), b.end(), 6);
	cout << dstDeque.first - b.begin() << " -> " << dstDeque.second - b.begin() << endl;

#elif 0
	/*
	fill:  fill_n
		填充元素/n个元素
	*/
	vector<int> a(10);
	fill(a.begin(), a.begin() + 4, 1);
	fill_n(a.begin() + 4, 6, 2);
	for (auto& x : a)
	{
		cout << x << " ";
	}
#elif 0
	/*
	find:
		Find value in range
	*/
	vector<int> a{ 1,2,3,4,5,6 };
	//找到元素5，返回的迭代器指向找到的此元素位置
	auto it = find(a.begin(), a.end(), 5);

	cout << *it << endl;
#elif 0
	/*
	find_end:
		Find last subsequance 返回符合条件的最后一个序列
	*/
	vector<int> a{ 1,2,3,4,5,1,2,3,9,10 };
	vector<int> b{ 1,2,3 };
	//123 两次出现在a容器中，但是返回的是最后一次出现的位置，即第二个1的位置
	auto it1 = find_end(a.begin(), a.end(), b.begin(), b.end());
	auto it2 = find_end(a.begin(), a.end(), b.begin(), b.end(), [](const int& a, const int& b) {return a == b; });

	cout << it1 - a.begin() << endl;		//下标： 5
	cout << it2 - a.begin() << endl;		//下标： 5

#elif 0
	/*
	find_first_of
	*/
	vector<int> a{ 1,2,3,4,5,6 };
	vector<int> b{ 3,4,5 };

	//返回找到的第一个元素的位置下标：用于两个容器查找第一个交集
	auto it = find_first_of(a.begin(), a.end(), b.begin(), b.end());
	cout << it - a.begin() << endl;		// 2
#elif 0
	/*
	find_if:
		Returns an iterator to the first element in the range [first,last) for which pred returns true. If no such element is found, the function returns last.
	*/
	vector<int> a{ 1,2,3,4,5,6 };
	//返回找到的第一个pred为true的下标位置：用于一个容器
	auto it = find_if(a.begin(), a.end(), [](const int& a) {return a % 2 == 1; });
	cout << it - a.begin() << endl;			//0
#elif 0
	/*
	find_if_not
		Returns an iterator to the first element in the range [first,last) for which pred returns false. If no such element is found, the function returns last.
	*/
	vector<int> a{ 1,2,3,4,5,6 };
	//返回找到的第一个pred为false的下标位置：用于一个容器
	auto it = find_if_not(a.begin(), a.end(), [](const int& a) {return a % 2 == 1; });
	cout << it - a.begin() << endl;		//元素2： 1
#elif 0
	/*
	for_each:
		Applies function fn to each of the elements in the range [first,last)
	*/
	vector<int> a{ 1,2,3,4,5,6 };
	//作用于容器的每一个元素
	for (auto& x : a)
	{
		cout << x << " ";
	}
	cout << endl;
	//如果元素是个偶数，则*=10；
	for_each(a.begin(), a.end(), [](int& a) {if (!(a % 2)) { a *= 10; }});

	for (auto& x : a)
	{
		cout << x << " ";
	}
#endif

#if 0
	/*
	generate:
	generate_n
	*/
	srand(time(0));
	vector<int> a{ 1,2,3,4,5,6 };
	vector<int> b(a.size());
	vector<int> c(a.size());
	//此函数不会接受参数，从函数返回值到序列中
	generate(b.begin(), b.end(), []() {return  rand() % 100; });
	generate_n(c.begin(), 5, Foo());	//_n只接受前n个元素的改变

	for (auto& x : b)
	{
		cout << x << " ";
	}
	cout << endl;

	for (auto& x : c)
	{
		cout << x << " ";
	}
	cout << endl;
#elif 0
	/*
	includes:
		Test whether sorted range includes another sorted range
	*/
	//注意：他们必须是有序的容器
	vector<int> a{ 1,1,2,2,3,3,4,5,6,7,8,9 };
	list<int> b{ 1 };
	if (includes(a.begin(), a.end(), b.begin(), b.end()))
	{
		cout << "这两个容器相互包含\n";
	}
	else
	{
		cout << "不包含\n";
	}
	cout << includes(a.begin(), a.end(), b.begin(), b.end(), [](const int& a, const int& b) {return a < b; });
#elif 0
	/*
	inplace_merge:
		合并连续排序范围
		合并两个连续的排序范围:[first,middle)和[middle,last)，将结果放入组合的排序范围[first,last)中。
	*/
	int a1[]{ 1,2,3,4,5 };
	int a2[]{ 16,17,18,9,10 };
	vector<int> a(10);

	vector<int> b{ 1,2,3 };
	//拷贝元素到a容器
	auto it = copy(begin(a1),end(a1), a.begin());
	copy(begin(a2),end(a2),it);

	inplace_merge(a.begin(), a.begin() + 5, a.end());
	for (auto& x : a)
	{
		cout << x << " ";
	}
#elif 0
	/*
	is_heap
	make_heap
	*/
#elif 0
	/*
	is_partitioned  partition
	*/
	vector<int> a{ 1,9,5,6,2,4,3,6,8,7,11,51};
	partition(a.begin(), a.end(), [](const int& a) {return a > 10; });
	if (is_partitioned(a.begin(), a.end(), [](const int& a) {return a > 10; }))
	{
		cout << "a容器是按照规则的\n";
	}
	for (auto& x : a)
	{
		cout << x << " ";
	}
#elif 0
	/*
	is_permutation:
		比较两个容器（必选是相同的元素个数）的元素，即使顺序不同，只要元素相同，则true
	*/
	vector<int> a{ 1,2,3,4,5,6,7,8,9};
	vector<int> a1{ 9,8,7,6,5,3,4,1,2 };
	//元素个数相同
	if (is_permutation(a.begin(), a.end(), a1.begin()))
	{
		cout << "两个容器所含元素相同\n";
	}
#elif 0
	/*
	is_sorted
		is_sorted_until 返回第一个不符合排序的元素的位置
	*/
	vector<int> a{ 1,2,3,4,5,6,7,8,9 };
	vector<int> a1{ 9,8,7,18,5,4,3,2,1,};
	/*if (is_sorted(a1.begin(), a1.end(),less<>()))
	{
		cout << "元素正序\n";
	}
	else if (is_sorted(a1.begin(), a1.end(), greater<int>()))
	{
		cout << "元素倒序\n";
	}*/
	//18 不符合排序，返回指向18的迭代器
	auto fnit=is_sorted_until(a1.begin(), a1.end(),greater<int>());
	cout << *fnit << endl;

#endif

#if 0
	/*
	iter_swap 
		交换两个迭代器指向的元素
	*/
	vector<int> a{ 1,2,3,4,5,6};
	deque<int> b{ 9,8,7,6,5,4 };
	for (auto& x : a)
	{
		cout << x << " ";
	}
	cout << endl;
	for (auto& x : b)
	{
		cout << x << " ";
	}
	cout << endl;

	iter_swap(a.begin(), b.begin());
	for (auto& x : a)
	{
		cout << x << " ";
	}
	cout << endl;
	for (auto& x : b)
	{
		cout << x << " ";
	}
	cout << endl;
#elif 0
	/*
	lexicographical_compare
	*/
	vector<string> a{ "acde"};
	vector<string> b{ "bbcd "};

	cout << boolalpha << lexicographical_compare(a.begin(), a.end(), b.begin(), b.end()) << endl;

	map<int, int> a;
	multimap<int, int> b;
	unordered_map<int, int> c;
#elif 0
	/*
	lower_bound	:	下界
	upper_bound	：	上届	
	*/
	vector<int> a{ 1,2,3,4,5,6 };
	//返回指向找到的低于等于val的最大的元素迭代器
	auto it=lower_bound(a.begin(), a.end(), 3);
	//返回指向找到的大于val的最小的元素迭代器
	auto itmax = upper_bound(a.begin(), a.end(), 3);
	/*
	3 2
	4 3
	*/
	cout << *it << " " << it - a.begin() << endl;
	cout << *itmax << " " << itmax - a.begin() << endl;
#elif 0
	/*
	max 
	max_element
	min 
	min_element
	*/
	vector<int> a{ 9,5,7,8,6,2,1 };
	//用于普通元素
	auto it = max(7,9);
	//用于寻找容器的最大值元素
	auto itmaxiter = max_element(a.begin(), a.end());
	auto it1 = min(5, 6);
	auto itminiter = min_element(a.begin(), a.end());
	cout << it << endl;
	cout << *itmaxiter << endl;

	cout << it1 << endl;
	cout << *itminiter << endl;
#elif 0
	/*
	merge：
		Combines the elements in the sorted ranges [first1,last1) and [first2,last2), into a new range beginning at result with all its elements sorted.
	*/
	vector<int> a{ 1,2,3,4,5,6 };
	deque<int> b{ 5,6,7,8,9 };
	list<int> c(100,0);
	//合并容器元素，可以包含多个不同的容器，返回Dest的最后的end迭代器
	auto citer=merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
	c.resize(distance(c.begin(), citer));
	for (auto& x : c)
	{
		cout << x << "";
	}
#elif 0
	/*
	minmax：
		返回最小的和最大的元素
	minmax_element
		返回容器中的min和max元素
	*/
	//函数接受一个initialize_list作为参数，不接受容器，返回值为pair类型，first为min元素，second为max元素
	auto minAmax = minmax({ 1,2,3,4,5,6 });
	cout << minmax(5, 9).first << endl;
	cout << minAmax.first << " " << minAmax.second << endl;

	vector<int> a{1,5,9,8,7,1,23,5,0 };
	auto it = minmax_element(a.begin(), a.end());
	cout << *it.first << " " << *it.second << endl;

#endif

#if 0
	/*
	mismatch 
		返回两个容器不同的第一个位置
	*/
	vector<int> a{ 10,20,30 };
	deque<int> b{ 10,20,50,60,70,160 };
	//注意：第二个序列长度要大于等于第一个序列，因为比较是从第一个序列开始的，否则会造成越界
	auto diff = mismatch(a.begin(), a.end(), b.begin());
	cout << *diff.first << " : " << *diff.second << endl;
#elif 1
	/*
	move：
		相等于容器的复制
	move_backward：
		从后往前移动
	*/
	vector<int> a{ 1,2,3,4,5,6,7,8};
	vector<int> temp(a.size());
	vector<int> endc(a.size());
	//返回一个指向dest的尾后迭代器
	auto it=move(a.begin(), a.end(), temp.begin());
	//从后往前移动，返回指向dest的首元素迭代器
	auto itbeg=move_backward(a.begin(), a.end(), endc.end());
	cout << *itbeg << endl;
	
#endif
	return 0;
}