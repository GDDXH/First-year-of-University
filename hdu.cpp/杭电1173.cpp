#include<iostream>  
#include<cstdio>
#include<algorithm>  
using namespace std;   
double arrx[1000001],arry[1000001];   
int main()  
{  
  int i,j,num;  
  while(cin>>num && num!=0)  
  {  
      for(i=0;i<num;i++)  
      	scanf("%lf%lf",&arrx[i],&arry[i]);  
      sort(arrx,arrx+num);  
      sort(arry,arry+num);  
      printf("%.2f %.2f\n",arrx[(num-1)/2],arry[(num-1)/2]);  
  }  
  return 0;  
} 
