/*1、先看被除数的第一位够不够除,如果够除,就把商写在被除数的第一位上面.
2、如果不够除,就要看到被除数的第二位,看到哪一位,就要把商写在哪一位的上面.*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int m;
	string n;
	while(cin>>n>>m)
	{
		int remainder=0;
		for(int i=0;i<n.size();i++)
		{
			remainder=remainder*10+n[i]-'0';
			remainder%=m;	
		}
		cout<<remainder<<endl;		
	}
	return 0;	
} 
