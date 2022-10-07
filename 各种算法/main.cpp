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
		���pred�Է�Χ[��һ�������һ��]�е�����Ԫ�ض�����true�����߷�ΧΪ�գ��򷵻�true�����򷵻�false
	*/

	vector<int> a{ 1,3,5,7,9,11 };
	//�ж����е�Ԫ��Ϊ����
	auto it = all_of(a.begin(), a.end(), [](const int& data) {return data % 2; });
	cout << boolalpha << it << endl;
#elif 0
	/*
	any_of:
		���pred�Է�Χ[��һ�������һ��]�е�����Ԫ�ط���true�����߷�ΧΪ�գ��򷵻�true�����򷵻�false
	*/

	vector<int> a{ 2,4,5,8,10,12 };
	//�ж�������������Ԫ��
	auto it = any_of(a.begin(), a.end(), [](const int& data) {return data % 2; });
	cout << boolalpha << it << endl;
#elif 0
	/*
	binary_search��
		���ֲ���
	*/
	vector<int> a{ 1,2,3,4,5,6,7,8,9,10 };
	//����Ԫ��12��false
	cout << boolalpha << binary_search(a.begin(), a.end(), 12) << endl;
#elif 0
	/*
	copy:
		����Ԫ�� Copies the elements in the range [first,last) into the range beginning at result.
	*/
	deque<int> a{ 1,2,3,4,5,6 };
	deque<int> b(a.size()); //����Ҫ�ȸ�Ŀ���������������ʵ�����
	//���������ڵ�Ԫ�أ�ע�⣺����Ŀ���end������
	auto it = copy(a.begin(), a.end(), b.begin());
	for (auto& x : b)
	{
		cout << x << " ";
	}
#elif 0
	/*
	copy_backward:
		���ſ���������Ԫ��
	*/
	deque<int> a{ 1,2,3,4,5,6 };
	deque<int> b(a.size()); //����Ҫ�ȸ�Ŀ���������������ʵ�����
	//���ſ��������ڵ�Ԫ�أ����ص�һ��Ԫ�صĵ�������ע��Ҫ����dstһ��end�Ŀ�ʼλ�ã���Ϊ���ǴӺ���ǰ���Ƶģ���������Ԫ��˳�򲻱�
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
	//���a��Ԫ�ش�������������������Ƹ�Dst����������ָ������һ��Ԫ�ص�����
	auto it = copy_if(a.begin(), a.end(), Dst.begin(), [](const int& data) {return data % 2; });
	//��������Ŀ�������Ĵ�С
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
	size_t pos = 5;	//Խ�籨��
	//����a������ǰpos��Ԫ�ص�Ŀ������
	auto it = copy_n(a.begin(), pos, Dst.begin());
	Dst.resize(distance(Dst.begin(), it));
	for (auto& x : Dst)
	{
		cout << x << " ";
	}
#elif 0
	/*
	count:
		ͳ�Ƶ���val��Ԫ�صĸ������Զ���������Ҫ����operator==�����
	*/
	vector<int> a{ 9,8,7,6,5,5,5,5,5,3,2,1 };
	//����a������ǰpos��Ԫ�ص�Ŀ������
	cout << count(a.cbegin(), a.cend(), 5) << endl;
#elif 0
	/*
	count_if:
		���������������ͳ��Ԫ��
	*/
	vector<int> a{ 1,2,3,4,5,6 };
	//ͳ�Ƶ���5��Ԫ�صĸ���
	cout << count_if(a.begin(), a.end(), bind(equal_to<int>(), placeholders::_1, 5)) << endl;
#endif

#if 0
	/*
	equal:
		�Ƚ��������е�Ԫ���Ƿ����
	*/
	vector<int> a{ 1,2,3,4,5,6 };
	vector<int> b{ 1,2,3,5,6,7 };
	//The comparison includes up to as many elements of this sequence as those in the range [first1,last1). ����������Ԫ�ظ����������
	cout << boolalpha << equal(a.begin(), a.end(), b.begin()) << endl;
	//ͨ���˵��ñȽ�������һ�����Ƿ����
	cout << boolalpha << equal(a.begin(), a.begin() + 3, b.begin(), b.begin() + 3, [](const int& a1, const int& a2) {return a1 == a2; }) << endl;
#elif 0
	/*
	equal_range

	*/
	vector<int> a{ 1,2,3,4,5,6,7,8,9 };
	deque<int> b{ 3,4,5,6,6,6,7,8,9,10 };
	//pair������Ϊ����ֵ��firstָ������ϵĵ�һ��Ԫ�ص��±�λ�ã�secondָ����ϵ����һ��Ԫ�ص���һ��λ�ã�ע�����Ͳ�ͬ��pair����Ҳ��ͬ
	pair<vector<int>::iterator, vector<int>::iterator> dst;
	pair<deque<int>::iterator, deque<int>::iterator> dstDeque;
	//�±꣺ 3 ----- 7
	dstDeque = equal_range(b.begin(), b.end(), 6);
	cout << dstDeque.first - b.begin() << " -> " << dstDeque.second - b.begin() << endl;

#elif 0
	/*
	fill:  fill_n
		���Ԫ��/n��Ԫ��
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
	//�ҵ�Ԫ��5�����صĵ�����ָ���ҵ��Ĵ�Ԫ��λ��
	auto it = find(a.begin(), a.end(), 5);

	cout << *it << endl;
#elif 0
	/*
	find_end:
		Find last subsequance ���ط������������һ������
	*/
	vector<int> a{ 1,2,3,4,5,1,2,3,9,10 };
	vector<int> b{ 1,2,3 };
	//123 ���γ�����a�����У����Ƿ��ص������һ�γ��ֵ�λ�ã����ڶ���1��λ��
	auto it1 = find_end(a.begin(), a.end(), b.begin(), b.end());
	auto it2 = find_end(a.begin(), a.end(), b.begin(), b.end(), [](const int& a, const int& b) {return a == b; });

	cout << it1 - a.begin() << endl;		//�±꣺ 5
	cout << it2 - a.begin() << endl;		//�±꣺ 5

#elif 0
	/*
	find_first_of
	*/
	vector<int> a{ 1,2,3,4,5,6 };
	vector<int> b{ 3,4,5 };

	//�����ҵ��ĵ�һ��Ԫ�ص�λ���±꣺���������������ҵ�һ������
	auto it = find_first_of(a.begin(), a.end(), b.begin(), b.end());
	cout << it - a.begin() << endl;		// 2
#elif 0
	/*
	find_if:
		Returns an iterator to the first element in the range [first,last) for which pred returns true. If no such element is found, the function returns last.
	*/
	vector<int> a{ 1,2,3,4,5,6 };
	//�����ҵ��ĵ�һ��predΪtrue���±�λ�ã�����һ������
	auto it = find_if(a.begin(), a.end(), [](const int& a) {return a % 2 == 1; });
	cout << it - a.begin() << endl;			//0
#elif 0
	/*
	find_if_not
		Returns an iterator to the first element in the range [first,last) for which pred returns false. If no such element is found, the function returns last.
	*/
	vector<int> a{ 1,2,3,4,5,6 };
	//�����ҵ��ĵ�һ��predΪfalse���±�λ�ã�����һ������
	auto it = find_if_not(a.begin(), a.end(), [](const int& a) {return a % 2 == 1; });
	cout << it - a.begin() << endl;		//Ԫ��2�� 1
#elif 0
	/*
	for_each:
		Applies function fn to each of the elements in the range [first,last)
	*/
	vector<int> a{ 1,2,3,4,5,6 };
	//������������ÿһ��Ԫ��
	for (auto& x : a)
	{
		cout << x << " ";
	}
	cout << endl;
	//���Ԫ���Ǹ�ż������*=10��
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
	//�˺���������ܲ������Ӻ�������ֵ��������
	generate(b.begin(), b.end(), []() {return  rand() % 100; });
	generate_n(c.begin(), 5, Foo());	//_nֻ����ǰn��Ԫ�صĸı�

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
	//ע�⣺���Ǳ��������������
	vector<int> a{ 1,1,2,2,3,3,4,5,6,7,8,9 };
	list<int> b{ 1 };
	if (includes(a.begin(), a.end(), b.begin(), b.end()))
	{
		cout << "�����������໥����\n";
	}
	else
	{
		cout << "������\n";
	}
	cout << includes(a.begin(), a.end(), b.begin(), b.end(), [](const int& a, const int& b) {return a < b; });
#elif 0
	/*
	inplace_merge:
		�ϲ���������Χ
		�ϲ���������������Χ:[first,middle)��[middle,last)�������������ϵ�����Χ[first,last)�С�
	*/
	int a1[]{ 1,2,3,4,5 };
	int a2[]{ 16,17,18,9,10 };
	vector<int> a(10);

	vector<int> b{ 1,2,3 };
	//����Ԫ�ص�a����
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
		cout << "a�����ǰ��չ����\n";
	}
	for (auto& x : a)
	{
		cout << x << " ";
	}
#elif 0
	/*
	is_permutation:
		�Ƚ�������������ѡ����ͬ��Ԫ�ظ�������Ԫ�أ���ʹ˳��ͬ��ֻҪԪ����ͬ����true
	*/
	vector<int> a{ 1,2,3,4,5,6,7,8,9};
	vector<int> a1{ 9,8,7,6,5,3,4,1,2 };
	//Ԫ�ظ�����ͬ
	if (is_permutation(a.begin(), a.end(), a1.begin()))
	{
		cout << "������������Ԫ����ͬ\n";
	}
#elif 0
	/*
	is_sorted
		is_sorted_until ���ص�һ�������������Ԫ�ص�λ��
	*/
	vector<int> a{ 1,2,3,4,5,6,7,8,9 };
	vector<int> a1{ 9,8,7,18,5,4,3,2,1,};
	/*if (is_sorted(a1.begin(), a1.end(),less<>()))
	{
		cout << "Ԫ������\n";
	}
	else if (is_sorted(a1.begin(), a1.end(), greater<int>()))
	{
		cout << "Ԫ�ص���\n";
	}*/
	//18 ���������򣬷���ָ��18�ĵ�����
	auto fnit=is_sorted_until(a1.begin(), a1.end(),greater<int>());
	cout << *fnit << endl;

#endif

#if 0
	/*
	iter_swap 
		��������������ָ���Ԫ��
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
	lower_bound	:	�½�
	upper_bound	��	�Ͻ�	
	*/
	vector<int> a{ 1,2,3,4,5,6 };
	//����ָ���ҵ��ĵ��ڵ���val������Ԫ�ص�����
	auto it=lower_bound(a.begin(), a.end(), 3);
	//����ָ���ҵ��Ĵ���val����С��Ԫ�ص�����
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
	//������ͨԪ��
	auto it = max(7,9);
	//����Ѱ�����������ֵԪ��
	auto itmaxiter = max_element(a.begin(), a.end());
	auto it1 = min(5, 6);
	auto itminiter = min_element(a.begin(), a.end());
	cout << it << endl;
	cout << *itmaxiter << endl;

	cout << it1 << endl;
	cout << *itminiter << endl;
#elif 0
	/*
	merge��
		Combines the elements in the sorted ranges [first1,last1) and [first2,last2), into a new range beginning at result with all its elements sorted.
	*/
	vector<int> a{ 1,2,3,4,5,6 };
	deque<int> b{ 5,6,7,8,9 };
	list<int> c(100,0);
	//�ϲ�����Ԫ�أ����԰��������ͬ������������Dest������end������
	auto citer=merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
	c.resize(distance(c.begin(), citer));
	for (auto& x : c)
	{
		cout << x << "";
	}
#elif 0
	/*
	minmax��
		������С�ĺ�����Ԫ��
	minmax_element
		���������е�min��maxԪ��
	*/
	//��������һ��initialize_list��Ϊ����������������������ֵΪpair���ͣ�firstΪminԪ�أ�secondΪmaxԪ��
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
		��������������ͬ�ĵ�һ��λ��
	*/
	vector<int> a{ 10,20,30 };
	deque<int> b{ 10,20,50,60,70,160 };
	//ע�⣺�ڶ������г���Ҫ���ڵ��ڵ�һ�����У���Ϊ�Ƚ��Ǵӵ�һ�����п�ʼ�ģ���������Խ��
	auto diff = mismatch(a.begin(), a.end(), b.begin());
	cout << *diff.first << " : " << *diff.second << endl;
#elif 1
	/*
	move��
		����������ĸ���
	move_backward��
		�Ӻ���ǰ�ƶ�
	*/
	vector<int> a{ 1,2,3,4,5,6,7,8};
	vector<int> temp(a.size());
	vector<int> endc(a.size());
	//����һ��ָ��dest��β�������
	auto it=move(a.begin(), a.end(), temp.begin());
	//�Ӻ���ǰ�ƶ�������ָ��dest����Ԫ�ص�����
	auto itbeg=move_backward(a.begin(), a.end(), endc.end());
	cout << *itbeg << endl;
	
#endif
	return 0;
}