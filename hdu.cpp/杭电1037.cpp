#include<iostream>
using namespace std;
int main()
{
	int n1,n2,n3;
	cin>>n1>>n2>>n3;
	if(n1>168&&n2>168&&n3>168)
	{
		cout<<"NO CRASH";
	}
	else
	{
		if(n1<=168)
		cout<<"CRASH "<<n1<<endl;
		if(n2<=168)
		cout<<"CRASH "<<n2<<endl;
		if(n3<=168)
		cout<<"CRASH "<<n3<<endl;
	}
	return 0; 
}
