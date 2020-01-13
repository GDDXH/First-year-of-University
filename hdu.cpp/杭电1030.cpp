#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n1,n2;
	int t;
	int x1,y1,z1,x2,y2,z2;
	while(cin>>n1>>n2)
	{
		x1=sqrt(n1-1)+1;
		x2=sqrt(n2-1)+1;
		y1=(x1*x1-n1)/2+1;
		y2=(x2*x2-n2)/2+1;
		z1=(n1-(x1-1)*(x1-1)-1)/2+1;
		z2=(n2-(x2-1)*(x2-1)-1)/2+1;
		t=abs(x1-x2)+abs(y1-y2)+abs(z1-z2);
		cout<<t<<endl;
	}
	return 0;
	
}
