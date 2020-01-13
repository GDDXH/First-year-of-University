#include<iostream>//codeforcesµÄÌâÄ¿ 
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<string>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;
int main()
{
	int i,size,k=0,flag;
	string s1,s2,old_name[1010],new_name[1010];
	cin>>size;
	while(size--)
	{
		cin>>s1>>s2;
		flag=0;
		for(i=0;i<k;i++)
		{
			if(s1==new_name[i])
			{
				new_name[i]=s2;
				flag=1;
				break; 
			}
		}
		if(flag==0)
		{
			old_name[k]=s1;
			new_name[k]=s2;
			k++;
		}
	}
	cout<<k<<endl;
	for(i=0;i<k;i++)
	{
		cout<<old_name[i]<<" "<<new_name[i]<<endl; 
	}
	return 0;
}
