#include<iostream> //ASCIIÂëÇóºÍ
#include<string>
using namespace std;
int main()
{
	string a;
	while(getline(cin,a))
	{
		int sum=0;
		if(a=="abcdef")
		{
			break;
		}
		for(int i=0;i<a.length();i++)
		{
			sum+=a[i];
		}
		cout<<sum<<endl;
	}
 } 
