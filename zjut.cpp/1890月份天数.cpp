#include<iostream>
using namespace std;
int isleap(int year)  
{  
    if((year%4==0&&year%100!=0)||year%400==0)
        return 1;  
    else  
        return 0;  
} 
int main()
{
	int year1[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};  
    int year2[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};  
    int year,month;
    while(cin>>year>>month,year&&month)
    {
    	if(month>12||month<1)
		{	
			cout<<"ERROR"<<endl;
    		continue;	
		}
		if(isleap(year))
			cout<<year2[month]<<endl;
		else	 
			cout<<year1[month]<<endl;
	}
}
