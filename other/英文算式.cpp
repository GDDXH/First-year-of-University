#include<iostream>
#include<cstring>
#include<string>
#include<cctype>
using namespace std;
int change(string s)
{
	if(s=="zero")	return 0;
	if(s=="one")  	return 1;
	if(s=="two") 	return 2;
	if(s=="three") 	return 3;
	if(s=="four") 	return 4;
	if(s=="five") 	return 5;
	if(s=="six") 	return 6;
	if(s=="seven") 	return 7;
	if(s=="eight") 	return 8;
	if(s=="nine") 	return 9;
}
int main()
{
	char s[10][10];
	int n[3];
	while(scanf("%s",s[0])!=EOF)
	{
		bool flag =false;
		scanf("%s%s%s%s",s[1],s[2],s[3],s[4]);
		for(int i=0;i<5;i++)
		{
			int len = strlen(s[i]);
			for(int j=0;j<len;j++)
				s[i][j] = tolower(s[i][j]);
		}
		n[0] = change(s[0]);
		n[2] = change(s[2]);
		n[4] = change(s[4]);
		if(!strcmp(s[1],"add"))
		{
			n[0]+=n[2];		
		}
		else if(!strcmp(s[1],"sub"))
		{
			n[0]-=n[2];		
		}
		else if(!strcmp(s[1],"mul"))
		{
			n[0]*=n[2];		
		}
		else
		{
			if(n[2]==0)//false
			{
				n[0]=1;
				n[4]=-1;
			}
			else
				n[0]/=n[2];		
		}
		cout<<(n[0]==n[4]?"true\n":"false\n");
	}
	return 0;
}
