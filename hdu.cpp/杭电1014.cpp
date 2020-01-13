#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a,b,c;
	while(cin>>a>>b)
	{
		int t;
		int a1=a;
		int b1=b;
		if(a<b)
		{
			t=a;
			a=b;
			b=t;			
		}
		while(t=a%b)
		{
			a=b;
			b=t;
		}
		if(b!=1)cout<<setw(10)<<a1<<setw(10)<<b1<<"    "<<"Bad Choice"<<endl<<endl;
		else cout<<setw(10)<<a1<<setw(10)<<b1<<"    "<<"Good Choice"<<endl<<endl;	
	}
	return 0;
 } 
