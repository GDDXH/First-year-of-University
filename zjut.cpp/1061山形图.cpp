#include<iostream>
#include<string>
using namespace std;
int main()
{
	char c;
	int h;
	while(cin>>c>>h)
	{
		for(int i=0;i<h;i++)
		{
			cout<<string(h-i-1,' ')+string(2*i+1,c)+'\n';
		}
	}
}
