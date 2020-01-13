#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int result[3][3]={{11,-1,17},{41,-1,47},{71,-1,79}};
	int t;
	char a[5];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
		cout << result[(a[0] - 'A') % 3][(a[1] - 'A') % 3] << endl;
	}
	return 0;
 } 
