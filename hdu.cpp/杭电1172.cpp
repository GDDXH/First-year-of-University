#include<iostream>  //猜数字  
using namespace std;  
int array[101][3];  
bool test(int a,int b)  
{  
    int d[4]={0};  
    int count1=0;//统计在正确位置的数字的个数  
    int count2=0;//统计猜对的数字个数  
    int array1[4];  
    int array2[4];  
    array1[0]=a%10;  
    array1[1]=(a/10)%10;  
    array1[2]=(a/100)%10;  
    array1[3]=(a/1000)%10;  
    array2[0]=array[b][0]%10;  
    array2[1]=(array[b][0]/10)%10;  
    array2[2]=(array[b][0]/100)%10;  
    array2[3]=(array[b][0]/1000)%10;  
    for(int m=0;m<4;m++)  
        if(array1[m]==array2[m])//计算在正确位置的数字的个数  
            count1++;  
        if(count1!=array[b][2])  
            return false;  
    for(int m=0;m<4;m++)  
    {  
        for(int n=0;n<4;n++)  
            if(array1[m]==array2[n]&&d[n]==0)  
            {  
                count2++;  
                d[n]=1;  
                break;  
            }  
    }  
    if(count2==array[b][1])  
        return true;  
    else  
        return false;  
}  
int main()  
{  
	int N;
	while(cin>>N&&N)
	{
		int A,B,C,t;
    	int counter=0;   
    	for(int i=0;i<N;i++)  
    	{  
        	cin>>A>>B>>C;  
        	array[i][0]=A;  
        	array[i][1]=B;  
        	array[i][2]=C;  
    	}  
    	for(int i=1000;i<=9999;i++)  
    	{  
        	bool flag=true;  
        	for(int j=0;j<N;j++)  
        	{  
            	flag=test(i,j);  
            	if(!flag)   
                	break;  
        	}  
       		if(flag)  
        	{  
            	counter++;  
            	t=i;  
        	}  
	    }  
    	if(counter==1)  
       		cout<<t<<endl;  
   		else  
        	cout<<"Not sure"<<endl; 
	}
    return 0;  
}  
/*
#include <iostream>   
#include <cstring>  
using namespace std;  
int main()  
{  
    int N,i,j,k,t,sum1,flag,flag2,sum2,sumall,Numfinal;  
    int A[110],B[110],C[110];  
    int num[4];  
    int flag1[4];  
    int sum[4];   
    while(cin>>N&&N)  
    {  
        flag=true;  
        sumall=0;  
        for(i=1;i<=N;i++)  
        {  
            cin>>A[i]>>B[i]>>C[i];
        }  
        for(i=1000;i<=9999;i++)  
        {  
            flag2=1;  
            for(j=1;j<=N;j++)  
            {  
                sum1=0;  
                memset(flag1,0,sizeof(flag1));  
                num[0]=A[j]/1000;  
                num[1]=A[j]/100-num[0]*10;  
                num[2]=A[j]/10-A[j]/100*10;  
                num[3]=A[j]%10;  
                sum[0]=i/1000;  
                sum[1]=i/100-sum[0]*10;  
                sum[2]=i/10-i/100*10;  
                sum[3]=i%10;  
                for(k=0;k<4;k++)  
                {  
                    for(t=0;t<4;t++)  
                    {  
                    	if(sum[k]==num[t]&&flag1[t]==0)  
                    	{  
                        	flag1[t]=1;  
                        	sum1++;  
                       		break;  
                   		}  
                    }  
                }  
                if(sum1!=B[j])  
                {  
                    flag2=0;  
                    break;  
                }  
                else   
                {  
                    sum2=0;  
                    if(sum[0]==num[0])  
                    sum2++;  
                    if(sum[1]==num[1])  
                    sum2++;  
                    if(sum[2]==num[2])  
                    sum2++;  
                    if(sum[3]==num[3])  
                    sum2++;  
                    if(sum2!=C[j])  
                    {  
                        flag2=0;  
                        break;  
                    }  
                }  
            }  
            if(flag2)  
            {  
                sumall++;  
                Numfinal=i;  
                if(sumall>=2)  
                {  
                    flag=false;  
                    break;
                }  
            }
            else
            {
            	continue;
			}
        }  
        if(flag)  
        {  
            cout<<Numfinal<<endl;  
        }  
        else   
        cout<<"Not sure"<<endl;
    }  
return 0;  
}  	*/
