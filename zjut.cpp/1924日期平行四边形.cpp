#include<iostream>
#include<string>
using namespace std;
int main()
{
        char a[11];
        while(cin>>a)
        {       
				int high=(a[5]-'0')*10+a[6]-'0';
                int width=(a[8]-'0')*10+a[9]-'0';
                for(int i=1;i<=high;i++)
                cout<<string(high-i,' ')+string(width,'X')<<endl;
                cout<<endl;
        }
        return 0;
}
