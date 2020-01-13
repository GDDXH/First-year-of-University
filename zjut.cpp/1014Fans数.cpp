#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char a[20];
	while(cin>>a)
	{
		int i;
		int sum=0;
		for(i=0;i<strlen(a);i++)
		{
			sum+=a[i]-'0';//-48
		}
		cout<<sum<<endl;
			
	}	
} 
