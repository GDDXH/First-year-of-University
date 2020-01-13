#include<iostream>
#include<string>
using namespace std;
int main() 
{
	char c;
	int w,h,r,s=0;
	while(cin>>c>>w>>h>>r)
	{
		if(s++)
			cout<<endl;
		if(h%2==0)
		{
			cout<<string(w,c)<<endl;
			for(int i=1;i<=(h-1)*r;i++)
			{
				int j=i%(h-1);
				if(j<h/2)
					cout<<string(j,' ');
	 			else
	 				cout<<string(h-1-j,' ');
				if(i%2!=0)
				{
					for(int k=0;k<w/2;k++)
						cout<<c<<" ";
					cout<<c<<endl;
				}
				else 
					cout<<string(w,c)<<endl; 
			}
		}
		else
		{
			cout<<string(w,c)<<endl;
			for(int i=1;i<=r;i++)
			{
				for(int j=0;j<h-1;j++)
				{
					if(j<h/2)
						cout<<string(j+1,' ');
					else
						cout<<string(h-2-j,' ');
					if(j%2==0)
					{
						for(int k=0;k<w/2;k++)
							cout<<c<<" ";
						cout<<c<<endl;
					}
					else 
						cout<<string(w,c)<<endl; 
					
				}
			}
		}
	}
}
