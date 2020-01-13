#include<iostream>
#include<string>
using namespace std;
bool isPalindromeString(string a)
{
	int index1=0,index2=a.length()-1;
	while(index1<index2)
	{
		if(a[index1]!=a[index2])
		{
			return false;
		}
		index1++;
		index2--; 
	}
	return true; 
}
int main()
{
	string password;
	string substring;
	int i,j;
	while(cin>>password)
	{
		int maxlength=0;
		for(i=0;i<password.length();i++)
		{
			int length=password.length()-i;
			for( j=0;j<length;j++)
			{
				substring=password.substr(i,j+1);
				if(isPalindromeString(substring))
				{
					maxlength=maxlength>j+1?maxlength:j+1;
				}
			}
		}
		cout<<maxlength<<endl;
	}
 } 
