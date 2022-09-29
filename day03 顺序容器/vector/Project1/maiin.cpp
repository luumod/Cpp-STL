#include <iostream>
#include <vector>
using namespace std;

int main()
{
	/*
	���췽ʽ
	*/
	vector<int> a{ 1,2,3,4,5,6 };	//�ۺϳ�ʼ��
	const vector<int> b(5);	//ָ����С
	vector<int> c(10, 0);	//ָ����С���ҳ�ʼ��Ϊ0
	vector<int> d(a.begin(), a.end());	//������һ������������
	vector<int> e(a);	
	vector<int> f(b);
	
	/*
	����Ԫ��
	*/
	cout << a[0] << endl;
	cout << a.at(5) << endl;
	cout << a.front() << endl;
	cout << a.back() << endl;
	auto p = a.data();	//����ָ�������һ��Ԫ�ص�ָ��

	/*
	�������
	*/
	cout << a.size() << endl;		//��ȡԪ�ظ���
	cout << a.max_size() << endl;	//���Դ洢�����Ԫ�ظ���
	cout << a.capacity() << endl;	//��ȡ��ǰ�����������Զ�����
	a.reserve(100);		//����������100
	cout << a.capacity() << endl;	//��ӡ��100
	a.resize(4);				//��������Ϊ4�������Ԫ�ػᱻ����
	a.resize(10, -99);	//��������Ϊ10����-99�����
	a.clear();						//�������Ԫ�ظ��������������ܵ���������
	cout << a.size() << endl;		//��ӡ��0   capacity��100
	cout << a.empty() << endl;	//�жϿ�����
	a.shrink_to_fit();
	cout << a.capacity() << endl;	//��������С�������ʵ��Ĵ�С����ǰԪ�ظ���0 ����С��0

	/*
	�������޸�
	*/
	vector<int> temp{ 9,8,7,6,5,4 };
	a.push_back(10);			//β������Ԫ��10
	a.pop_back();					//βɾ
	a.emplace(a.end(),10);//emplace�����������Ĺ��죬��a��ĩβ����Ԫ��10
	a.emplace_back(55);			//��β������һ��Ԫ��55
	a.assign(50, -99);	//�������ô�С������СΪ50��������-99���
	a.assign(b.begin(), b.end());	//����ͬ��˳����b����������

	a.insert(a.begin(), 555);	//�������Ŀ�ʼλ�ã�����һ��Ԫ��555
	a.insert(a.begin(), 10, 999);	//��a��begin��������10��999
	a.insert(a.end(), temp.begin(), temp.end());	//��a��ĩβ������temp��ָ����Χ��Ԫ��
	a.insert(a.end(), { 1,2,3 });	//��������ĩβ����һ���ۺ��б�

	a.erase(a.begin());		//ɾ��������begin����Ԫ��
	a.erase(a.begin(), a.begin() + 9);//ɾ��ָ����Χ�����Ԫ��
	a.swap(temp);			//��������vector������
	vector<int> null;
	a.swap(null);			//�������
	for (auto& x : a)
	{
		cout << x << " ";
	}
	
	return 0;
}