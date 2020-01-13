#include<iostream>
using namespace std;
int main()
{
	int t;
	int a[110];
	cin>>t;
	while(t--)
	{
		int m,x,i,j;
		cin>>m>>x;
		for(i=0;i<m;i++)
		{
			cin>>a[i];
		}
		x%=100;
		for(i=0;i<x;i++)
		{
			int temp = a[0];
			for(j=0;j<m-1;j++)
			{
					a[j]=(a[j]+a[j+1])%100; 
			} 
			a[j]=(a[j]+temp)%100;
		}
		for(i=0;i<m;i++)
		{
			cout<<a[i];
			if(i!=m-1)
			cout<<" ";
		}
		cout<<endl;
	}
 } 
