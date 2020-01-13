#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int t;
	char n[1001];
	while(cin>>n)
	{
		if(strcmp(n,"0")==0)   break;  
		int sum=0;
		t=strlen(n);
		for(int i=0;i<t;i++)
		{
			sum+=n[i]-'0';
		}
		while(sum>9)
		{
			sum=(sum-1)%9+1;
		}
		cout<<sum<<endl;
	}
	return 0;
} 



