#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int a[4],t,flag,amout=0;
	while(scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3]))
	{
		if(a[0]==0&&a[1]==0&&a[2]==0&&a[3]==0)
		{
			break;
		}
		if(amout==1)
		cout<<endl;
		flag=1;
		amout=1;
		sort(a,a+4);
		t=a[3];
		do
		{
			if(a[0]==0)
				continue;
			if(flag)
			{
				cout<<a[0]<<a[1]<<a[2]<<a[3];
				flag=0;
			}
			else if(t!=a[0])
			{
				cout<<endl<<a[0]<<a[1]<<a[2]<<a[3];
			}
			else
			{
				cout<<" "<<a[0]<<a[1]<<a[2]<<a[3];
			}
			t=a[0]; 
		}while(next_permutation(a,a+4));
		cout<<endl;
	}
}
