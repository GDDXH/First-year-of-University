//��Ŀ����˼�ǣ���ʼ��ȫ������Ϊ�㣬i��1��ʼ������ÿ�θı���Ϊi�����ĵƵ�״̬��0��1��������N���ж������ΪN�ĵƵ�����״̬��
//Ҳ����˵����i�����ĳ���Nʱ��N��ֵ�����ٸı䡣���������N����������ż�ԡ�
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int i,n;
    while(cin>>n)
	{
        int sum=1;
        for(i=1;i<=n/2;i++)
        {
        	if(n%i==0) sum++;
		}
        if(sum%2==0) 
			cout<<'0'<<endl;
        else 
			cout<<'1'<<endl;
    }

}
