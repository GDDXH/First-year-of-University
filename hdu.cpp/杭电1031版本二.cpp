#include <iostream>  
#include <string.h>  
#include <algorithm>  
#include <cmath>  
using namespace std;  
const int N=10005;  
#define mmin 1e-10  
struct digit{  
  double num;  
  int xuhao;  
}aa[N];  
bool cmp1(digit a,digit b){  
    if(fabs(a.num-b.num)<0.000001)  
        return a.xuhao<b.xuhao;  
    return a.num>b.num;  
}  
bool cmp2(digit a,digit b){  
    return a.xuhao>b.xuhao;  
}  
int main(){  
  //freopen("11.txt","r",stdin);  
  int n,m,k;  
  while(~scanf("%d%d%d",&n,&m,&k)){  
      double x;  
      for(int i=0;i<m;++i){  
          aa[i].num=0.0;  
      }  
      for(int j=0;j<n;++j){  
         for(int i=0;i<m;++i){  
           scanf("%lf",&x);  
           aa[i].num+=x;  
         }  
      }  
     for(int i=0;i<m;++i)  
          aa[i].xuhao=i+1;  
     sort(aa,aa+m,cmp1);  
     sort(aa,aa+k,cmp2);  
     for(int i=0;i<k-1;++i)  
         printf("%d ",aa[i].xuhao);  
     printf("%d",aa[k-1].xuhao);  
     printf("\n");  
  }  
  return 0;  
} 
