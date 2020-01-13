#include<iostream>
#include<string> 
using namespace std;
int main()
{
	string  s;
	int count=0;
	while(cin>>s)
	{
		if(s=="Yes")
			count++;
		else 
			count--;
		
	}
	if(count>0)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}









