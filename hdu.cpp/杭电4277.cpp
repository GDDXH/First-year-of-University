#include<iostream>//DFS
#include<set>
using namespace std;
int length[20];
set<long long int > result;
void DFS(int a ,int b,int c,int i,int n)//a>b>c
{
	if(i==n)
	{
		if(a>=b&&b>=c&&a<b+c)
		{
			long long int temp = a * 12345*12345 + b * 12345 + c;
			result.insert(temp);
		}
		return ;
	}
	else
	{
		DFS(a+length[i],b,c,i+1,n);
		DFS(a,b+length[i],c,i+1,n);
		DFS(a,b,c+length[i],i+1,n);	
	}
}
int main()
{
	int T,n;
	scanf("%d",&T); 
	while(T--)
	{
		result.clear();
		
		scanf("%d",&n);
		
		for(int i=0;i<n;i++)
		{
			scanf("%d",&length[i]);	
		}
		
		DFS(0,0,0,0,n);
		
		printf("%d\n",result.size());
	}
 } 
