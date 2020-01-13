#include<iostream>
using namespace std;
const double pi=3.14;
int main()
{
	int n1,n2,n3;
	while(cin>>n1>>n2>>n3)
	{
		int size1=n1*n1*pi/4;
		int size2=5*n2+n3;
		if(size1>=size2)
			cout<<"HAPPY"<<endl;
		else
			cout<<"SAD"<<endl;
	}
}
