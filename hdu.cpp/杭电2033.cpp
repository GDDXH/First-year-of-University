#include<iostream>
#include<cstdio>
#include<cstdlib> 
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	
	int n,a1,a2,a3,b1,b2,b3,r1,r2,r3;
    cin>>n;
    while(n--)
    {
        cin>>a1>>a2>>a3>>b1>>b2>>b3;
        r3=(a3+b3)%60;
        r2=(a3+b3)/60+a2+b2;
        r1=a1+b1+r2/60;
        r2%=60;
        cout<<r1<<' '<<r2<<' '<<r3<<endl;
    }
}
