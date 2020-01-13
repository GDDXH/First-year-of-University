#include<iostream>
using namespace std;
int main()
{
	int n1,n2,n3;
	while(cin>>n1>>n2>>n3,n1!=-1&&n2!=-1&&n3!=-1)
	{
		if(n1<=168)
		{
			cout<<"CRASH "<<n1<<endl;
			continue;
		}
		if(n2<=168)
		{
			cout<<"CRASH "<<n2<<endl;
			continue;
		}
		if(n3<=168)
		{
			cout<<"CRASH "<<n3<<endl;
			continue;
		}
		cout<<"NO CRASH"<<endl;	
	}
}
