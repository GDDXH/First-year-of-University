#include<iostream>
#include<string>
using namespace std;
struct my
{
	string s;
	int prime;
	int flag[4];
};

int main()
{
	int n;
	while(cin>>n,n)
	{
		my t,re;
		re.prime = 0,re.flag[0] = 0;
		for(int i=0;i<n;i++)
		{
			cin>>t.s;
			re.s = t.s;	
			for(int j=0;j<t.s.size();j++)
			{
				t.prime = 0; 
				t.flag[0]=t.flag[1]=t.flag[2]=t.flag[3]=0;
				if(t.s[j]=='2'){
					t.prime++;
					t.flag[0]=1;
				}
					else if(t.s[j]=='3'){
						t.prime++;
						t.flag[1]=1;
					}
						else if(t.s[j]=='5'){
							t.prime++;
							t.flag[2]=1;
						}
							else if(t.s[j]=='7'){
								t.prime++;
								t.flag[3]=1;
							}
				t.flag[0]=t.flag[0]+t.flag[1]+t.flag[2]+t.flag[3];
			}
			if(re.prime<t.prime)
			{
				re.s = t.s;
				re.prime = t.prime;
				re.flag[0] = t.flag[0];
			}	
			else if(re.prime==t.prime)
			{
				if(re.flag[0]<t.flag[0])
				{
					re.s = t.s;
					re.prime = t.prime;
					re.flag[0] = t.flag[0];
				}
				else if(re.flag[0]==t.flag[0])
				{
					if(re.s>t.s)
					{
						re.s = t.s;
						re.prime = t.prime;
						re.flag[0] = t.flag[0];	
					}
				}
			}
		}
		cout<<re.s<<endl;
	}
 } 
