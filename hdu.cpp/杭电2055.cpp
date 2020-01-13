#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
int main()
{
	char a; 
	int size,b;
	cin>>size;
	while(size--)
	{
		cin>>a>>b;
		if(a<='Z')
			cout<<a-64+b<<endl;
		else
			cout<<96-a+b<<endl;
	}
	return 0;
}
