#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		cout<<a*(a+1)*b*(b+1)/4<<endl;
	}
	return 0; 
}
