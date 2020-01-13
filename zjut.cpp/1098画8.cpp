#include<iostream>
#include<string> 
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char c;
		int n;
		cin>>c>>n;
		int x1= (n-2)/2;    //横线宽度  
        int x2= (n+6)/6;  	//竖线宽度 
        int x3= (n-3)/2;	//上圈竖线高度
		int x4=	(n-2)/2;	//下圈竖线高度
        cout<<string(x2,' ')+string(x1,c)<<endl;
        for(int i=1;i<=x3;i++)
		{
			cout<<string(x2,c)+string(x1,' ')+string(x2,c)<<endl;
		}
		cout<<string(x2,' ')+string(x1,c)<<endl;	 
		for(int i=1;i<=x4;i++)
		{
			cout<<string(x2,c)+string(x1,' ')+string(x2,c)<<endl;
		}
		cout<<string(x2,' ')+string(x1,c)<<endl;
		if(t!=0)
		cout<<endl;
	}	
 } 
