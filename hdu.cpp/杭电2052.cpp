#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int m,n;
    while(cin>>m>>n)
	{
		int i;
        cout<<"+";
        for(i=0;i<m;i++)
		{
            cout<<"-";
        }
        cout<<"+"<<endl;
        for(i=0;i<n;i++)
		{
            cout<<"|";
            for(int j=0;j<m;j++){
                cout<<" ";
            }
            cout<<"|"<<endl;
        }
        cout<<"+";
        for(i=0;i<m;i++){
            cout<<"-";
        }
        cout<<"+"<<endl<<endl;
    }
    return 0;

}
