#include "test.h"

void Test::test_num()//���ѡ�ֱ��,ȷ�����ظ�
{
	cout << endl;
	int len = num.size();
	sort(num.begin(),num.end());
	for (int i = 1;i < len;i++)
	{
		if (num[i] == num[i - 1])
		{
			cout << "���" << num[i] << "�ظ�,���򽫽���,���޸��ı��ļ�!!!!!!!!!" << endl;
			Sleep(3000);
			abort();
		}
	}

}

void Test::test_num(int n)
{
	int len = num.size();
	if (n <= 0 || n > Size)//���С�ڵ�������������,���׳��쳣
		throw n*1.0;
	for (int i = 0;i < len;i++)//�����ͬ,���׳��쳣
	{
		if (n == num[i])
			throw n;
	}
}

void Test::test_num(double n)
{
	bool sign = false;
	int t =(int) n;
	int len = num.size();
	if (t <= 0 || t > Size) //���С�ڵ�������������, ���׳��쳣
		throw n;
	for (int i = 0;i < len;i++)//û�д˱�����׳��쳣
	{
		if (n == num[i])
		{
			sign = true;
			return;
		}
	}
	if (!sign)
		throw t;
}

void Test::test_ID(string s)//
{
	int len = ID.size();
	if (s.size() != 12)//ѧ�Ų���12λ,���׳��쳣
		throw 1.0;
	for (int i = 0;i < len;i++)//ѧ���ظ�,���׳��쳣
	{
		if (s == ID[i])
			throw 1;
	}
}

bool Test::test_score(list  *head)
{
	list *p = head;
	while (p != NULL)
	{
		if (p->data.getSum_score() == 0)
		{
			cout << "������ί���,���ɳɼ�����" << endl;
			return false;
		}
		p = p->next;
	}
	return true;
}
