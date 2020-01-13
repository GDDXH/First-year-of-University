#include<iostream>
#include<algorithm>
#include<cstring> 
using namespace std;
char rule(char a,char b)
{
	return a>b;
}
int main()
{
	char n[201];
	while(cin>>n)
	{
		int Size=strlen(n);
		sort(n,n+Size,rule);
		cout<<n<<endl;		
	}	
}
