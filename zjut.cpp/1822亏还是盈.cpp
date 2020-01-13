#include<iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int size,i,num;
		cin>>size;
		int sum=0;
		for(i=0;i<size;i++)
		{
			cin>>num;
			num%=16;
			if(num<8)
				sum-=num;
			else
				sum+=16-num;
		}
		cout<<sum<<endl; 
	}
	return 0;
}
