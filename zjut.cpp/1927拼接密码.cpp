#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1,s2;
	while(cin>>s1>>s2)
	{
		string s3;
		s3+=s1[2];
		s3+=s1[6];	
		s3+=s1[1];
		s3+=s1[0];
		s3+=s1[8];
		s3+=s1[7];
		s3+=(s2[0]+1);
		s3+=(s2[1]+5);
		s3+=(s2[2]+6);
		s3+=(s2[3]+8);
		s3+=(s2[4]+2);
		s3+=(s2[5]+4);
		cout<<s3<<endl;
	}
 } 
