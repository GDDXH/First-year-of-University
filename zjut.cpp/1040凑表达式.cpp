#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a,b,c; 
	while(cin>>a>>b>>c,a||b||c)
	{
		bool flag = false;
		a=abs(a),b=abs(b),c=abs(c); 
		if(a==0||b==0||c==0||a==b||a==c||b==c)
			flag = true;
		if(a+b==c||a+c==b||b+c==a||a*b==c||a*c==b||b*c==a)
			flag = true;
		if(flag)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;	
	}
	return 0;
}
