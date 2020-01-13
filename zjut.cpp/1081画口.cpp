#include<iostream>
#include<string>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char c;
		int num;
		cin>>c>>num;
		cout<<string(4+num,c)<<endl;
		cout<<string(4+num,c)<<endl;
		for(int i=0;i<num;i++)
		{
			cout<<c<<c<<string(num,' ')<<c<<c<<endl;
		}
		cout<<string(4+num,c)<<endl;
		cout<<string(4+num,c)<<endl;
		cout<<endl;
	}
}
