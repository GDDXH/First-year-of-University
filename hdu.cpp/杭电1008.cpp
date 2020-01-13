#include<iostream>
using namespace std;
int main()
{
	int num,a[1000];
	while(cin>>num&&num!=0)
	{
		int sum=0;
		for(int i=1;i<=num;i++)
		{
			cin>>a[i];
		}
		sum=num*5+6*a[1];
		for(int i=1;i<num;i++)	
		{
			if(a[i]>a[i+1])
			{
			sum+=4*(a[i]-a[i+1]);
			}
			if(a[i]<a[i+1])
			{
			sum+=6*(a[i+1]-a[i]);
			}	
		}
		cout<<sum<<endl;
	}
}
