#include <iostream>
#include <algorithm>
#include <functional>
#include <list>
using namespace std;


class Foo
{
public:
	bool operator()(const int& data)
	{
		return data % 2 != 0;
	}
};
int main()
{

	/*
	Ԫ�ع���
	*/
	list<int> a{ 1,2,3,4,5,6,7,8,9 };
	list<int> b(a.begin(), a.end());
	list<int> c(10);
	list<int> d(10,-999);


	/*
	Ԫ�ط���
	*/
	cout << a.front() << endl;
	cout << a.back() << endl;

	/*
	list����
	*/
	cout << a.empty() << endl;
	cout << a.size() << endl;
	cout << a.max_size() << endl;
	a.resize(10);
	a.resize(20, -999);

	/*
	list�޸�
	*/
	a.push_back(999);
	a.push_front(666);
	a.pop_back();
	a.pop_front();


	/*
	list��������
	*/
	a.clear();
	list<int> temp{1,2,3,4,5,6};
	list<int> temp2(temp);
	a.splice(a.begin(),temp);		//��temp�������뵽aָ����λ�ã�temp�����ᱻ��գ�
	//list�ĵ�����������+-�Ȳ���
	a.splice(a.begin(), temp2, --temp2.end());	//��temp2������ָ��λ��Ԫ�ز��뵽a��ָ��λ��λ��

	for (auto& x : a)
	{
		cout << x << " ";
	}
	cout <<endl;
	/*
	remove�������
	*/
#if 0
	//ɾ�����е���val��ֵ��Ԫ��
	a.remove(6);		
	//remove_if ɾ������ν��pred�з���true��Ԫ��
	//����lamdba���ʽ��ɾ������ż��Ԫ��
	a.remove_if([&](const int& data) {return data % 2 == 0; });	
	//���÷º���ɾ������
	a.remove_if(Foo());		
	//���ò����󶨣�ɾ�����е���5��Ԫ��
	auto NotEqual = bind(equal_to<int>(), placeholders::_1, 5);	
	a.remove_if(NotEqual);
#endif


	list<int> unq{ 1,1,2,3,3,4,4,5,6,6,7,8,8 };
	//unq.unique();			//ȥ�أ�ɾ�����ڵ��ظ�Ԫ��
	//unique�㷨
	auto it=unique(unq.begin(), unq.end(),bind(equal_to<int>(),placeholders::_1,placeholders::_2));
	unq.erase(it, unq.end());
	
	a.sort(less<>());
	unq.merge(a);		//�ϲ���������������������������ֹ
	unq.sort();
	unq.reverse();
	for (auto& x : unq)
	{
		cout << x << " ";
	}

	return 0;
}