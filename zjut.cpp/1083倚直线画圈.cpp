#include<iostream>
#include<string>
using namespace std;
int main()
{
	char c;
	int w,h;
	while(cin>>c>>w>>h)
	{
		for(int i=0;i<w;i++)
		{
			cout<<"B"+string(w,' ')+string(h,c)+'\n';
		}
		for(int i=0;i<h;i++)
		{
			cout<<"B"+string(w,c)+string(h,' ')+string(w,c)<<endl;
		}
		for(int i=0;i<w;i++)
		{
			cout<<"B"+string(w,' ')+string(h,c)+'\n';
		}
		cout<<endl;
	}
	return 0;
 } 
