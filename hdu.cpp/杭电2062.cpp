/*����һ������ An = { 1, 2, ..., n}�����磬A1={1}��A3={1,2,3}��
���ǳ�һ���ǿ��Ӽ�Ԫ�ص�����Ϊһ���Ӽ����С������е������а��ֵ�˳������
���������Ǹ�����m�������С�*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	int n,i,k,s[30];//s[i]�ǵ�i��ĳ�ʼ��Ԫ�� 
	long long int m,g[21]={0,1,2,5};//g[i]��ÿ��ĸ���
	for(i=4;i<21;i++)
	{
		g[i]=(i-1)*g[i-1]+1;
	}
	while(cin>>n>>m)
	{
		for(i=0;i<22;i++)
		{
			s[i]=i;		
		}
		while(n>0&&m>0)
		{
			k=m/g[n]+(m%g[n]>0?1:0);
			cout<<s[k];
			for(i=k;i<=n;i++)
			{
				s[i]=s[i+1];//����s[i]++����wrong����� 
			}
			m-=((k-1)*g[n]+1);
			putchar(m==0?'\n':' ');  
			n--;
		}	
	}
	return 0;
} 
