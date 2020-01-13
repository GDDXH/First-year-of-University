#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char s[200];
	while(cin>>s)
	{
		int sum=0,i;
		int size=strlen(s);
		for(i=0;i<size;i++)
		{
			sum+=s[i]-'0';
		}
		cout<<sum<<endl;
	}
}
