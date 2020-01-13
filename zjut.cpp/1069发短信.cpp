#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	string s;
	double all = 0;
	map<char,int> letter;
	for(char c='A';c<='Z';c++)
	{
		if(c=='A'||c=='D'||c=='G'||c=='J'||c=='M'||c=='P'||c=='T'||c=='W')
			letter[c] = 1;
		else if(c=='B'||c=='E'||c=='H'||c=='K'||c=='N'||c=='Q'||c=='U'||c=='X')
			letter[c] = 2;	
		else if(c=='C'||c=='F'||c=='I'||c=='L'||c=='O'||c=='R'||c=='V'||c=='Y')
			letter[c] = 3;		
		else if(c=='S'||c=='Z')
			letter[c] = 4;
	}
	while(getline(cin,s)) 
	{
		double sum = 0;
		int len = s.size();
		for(int i = 0;i<len;i++)
		{
			if(s[i]>='a'&&s[i]<='z')
				s[i]-=32;
			if(s[i]==' ')
				sum +=0.5;
			else if(s[i]>='A'&&s[i]<='Z')
				sum += letter[s[i]] *0.5;
			else sum+=1;
		}
		sum++;
		all+=sum;
		cout<<sum<<endl;
	} 
	cout<<all<<endl;
 } 
