#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int num[110];
		int i,size,k,flag=1;
		cin>>size;
		for(i=0;i<size;i++)
		{
			cin>>num[i];
		}
		sort(num,num+size);	
		k=num[1]-num[0];
		for(i=2;i<size;i++)
		{
			if(k!=num[i]-num[i-1])
			{
				flag=0;
				break;
			}
		}
		if(flag)
			cout<<"yes"<<endl;
		else 
			cout<<"no"<<endl; 	
	}
}
