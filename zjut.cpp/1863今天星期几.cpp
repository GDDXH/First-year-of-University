#include<iostream>
using namespace std; 
char data[7][10]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};  
int isleap(int year)  
{  
    if((year%4==0&&year%100!=0)||year%400==0)
        return 1;  
    else  
        return 0;  
}  
int main()  
{  
    unsigned long year,month,day;  
    int year1[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};  
    int year2[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};  
 
    char *getdata;  
    while(cin>>year>>month>>day)  
    {           
        int days=0,i=0,j=0;  
        for(i=1;i<year;i++)  
        {  
            if(isleap(i))
                days+=366;  
            else  
                days+=365;  
        }  
        for(j=0;j<month;j++)  
        {  
            if(isleap(year))       
                days+=year2[j];       
            else  
                days+=year1[j];  
        }  
        days+=day;  
        getdata=data[days%7]; 
        cout<<getdata<<endl;
    }  
}  
