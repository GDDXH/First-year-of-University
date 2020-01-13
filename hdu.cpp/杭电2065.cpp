#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;
int a[23]={1,2,6,20,72,72,56,60,12,92,56,0,52,12,56,40,92,32,56,80,32,52,56};//从第三项（即20）开始，以20位周期循环 
int main()
{
	int t,sign;
	long long int n;
	while(cin>>t,t)
	{
		sign=1;
		while(t--)
		{
			cin>>n;
			if(n<23)
				cout<<"Case "<<sign<<": "<<a[n]<<endl;
			else
			{
				n=n%20;
				cout<<"Case "<<sign<<": "<<a[n]<<endl;
			}
			sign++;
		}
		cout<<endl;
	}
	return 0;
 } 
