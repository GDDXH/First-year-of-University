#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	int i,p,k,a[60];
	while(cin>>p>>k)
	{
		if(p==1)
		{
			cout<<"0\n";
			continue;
		}
		int sum = 0,step = 1,count=0;
		for(i=0;i<=p;i++)
			a[i] = 1;
		while(sum<(p+1)/2)
		{
			if(a[step] == 1)
			{
				count++;
				if(count == k )
				{	
					count = 0;
					a[step] = 0;
					sum++;
				}	
			}
			step++;
			if(step>p)
				step = 1;	
		}
		int flag = true;
		for(i=1;i<=p;i++)
		{
			if(a[i] == 1)
			{
				if(flag)
				{
					cout<<i;
					flag =false;
				}		
				else
					cout<<" "<<i;
			}	
		}
		cout<<endl;	
	}
	return 0;
}
