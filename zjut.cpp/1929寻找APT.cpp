#include<iostream>
#include<cstring>
using namespace std;
char c[101][101];
int f(int x,int y)
{	
	int sum=0;
	if (c[x][y]!='A') return 0;
	if (c[x-1][y]=='P'&&c[x-2][y]=='T') sum++;
	if (c[x-1][y+1]=='P'&&c[x-2][y+2]=='T') sum++;
	if (c[x][y+1]=='P'&&c[x][y+2]=='T') sum++;
	if (c[x+1][y+1]=='P'&&c[x+2][y+2]=='T') sum++;
	if (c[x+1][y]=='P'&&c[x+2][y]=='T') sum++;
	if (c[x+1][y-1]=='P'&&c[x+2][y-2]=='T') sum++;
	if (c[x][y-1]=='P'&&c[x][y-2]=='T') sum++;
	if (c[x-1][y-1]=='P'&&c[x-2][y-2]=='T') sum++;
	return sum;
}
int main()
{
	int m,n;
	while(cin>>m>>n)
	{
		memset(c,0,sizeof(c));
		int sum=0;
		for (int i=1;i<=m;i++)
	    	for (int j=1;j<=n;j++)
	      		cin>>c[i][j];
	    for (int i=1;i<=m;i++)
	    	for (int j=1;j<=n;j++)
	       		sum+=f(i,j);
		cout<<sum<<endl;
	}	
}
