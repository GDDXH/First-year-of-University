/*1���ȿ��������ĵ�һλ��������,�������,�Ͱ���д�ڱ������ĵ�һλ����.
2�����������,��Ҫ�����������ĵڶ�λ,������һλ,��Ҫ����д����һλ������.*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int m;
	string n;
	while(cin>>n>>m)
	{
		int remainder=0;
		for(int i=0;i<n.size();i++)
		{
			remainder=remainder*10+n[i]-'0';
			remainder%=m;	
		}
		cout<<remainder<<endl;		
	}
	return 0;	
} 
