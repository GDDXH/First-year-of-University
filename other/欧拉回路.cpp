#include<iostream>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m) 
	{
		bool flag =true;
		int map[110]={0},a,b;
		for(int i=0;i<m;i++)
		{
			cin>>a>>b;
			map[a]++;
			map[b]++;
		}
		for(int i=1;i<=n;i++)
		{
			if(map[i]%2!=0)
			{
				flag = false;
			}
		}
		if(flag)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	
}
