#include<iostream>
#include<cstdio>
#include<cstdlib> 
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	int i,j,t;
	int a[30][30];
	a[0][0]=1;
	for(i=1;i<30;i++)
	{
		a[i][0]=1;
		a[i][i]=1;
		for(j=1;j<i;j++)
		{
			a[i][j]=a[i-1][j]+a[i-1][j-1];
		}
	} 
	while(cin>>t)
	{
		for(i=0;i<t;i++)
		{
			for(j=0;j<i;j++)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<a[i][j]<<endl;
		}
		cout<<endl;
	}
	return 0;
}
