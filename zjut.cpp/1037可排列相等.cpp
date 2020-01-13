#include<iostream>
#include<algorithm>
#include<string >
using namespace std;
int main()
{
	string s1,s2,s3;
	while(getline(cin,s1)&&getline(cin,s2))
	{
		getline(cin,s3);
		sort(s1.begin(),s1.end());
		sort(s2.begin(),s2.end());
		if(s1==s2)
		cout<<"yes"<<endl;
		else
		cout<<"no"<<endl; 
	}
	return 0 ;
}
