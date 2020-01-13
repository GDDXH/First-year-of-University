#include<iostream>
using namespace std;
int main()
{
	int n1,n2,n3,t;
	cin>>n1;
	for(int i=1;i<=n1;i++)
	{
		cin>>n2;
		int max=-1000;
		int sum=0;
		int begin=t=1;
		int end;
		for(int j=1;j<=n2;j++)
		{
			cin>>n3;
			sum+=n3;
			if(sum>=max)
			{
				max=sum;
				begin=t;
				end=j;	
			}
			if(sum<0)
			{
				sum=0;
				t=j+1;								
			}			
		}
		cout<<"Case "<<i<<":"<<endl;
		cout<<max<<" "<<begin<<" "<<end<<endl;
		if(i<n1) cout<<endl;
	}
	return 0;	
} 
