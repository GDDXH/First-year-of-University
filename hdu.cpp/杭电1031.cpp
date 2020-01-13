#include <cstdio>  
#include <cstdlib>  
struct element{  
    int id;  
    double sa;  
}e[10000];  
int cmp(const void *a,const void *b){  
    return (*(element*)a).sa>(*(element*)b).sa?-1:1;  
}  
int cmp2(const void *a,const void *b){  
    return (*(element*)b).id-(*(element*)a).id;  
}  
int main(){  
    int n,m,k;  
    double x;  
    while(~scanf("%d%d%d",&n,&m,&k)){  
        for(int i=0;i<10000;i++){  
            e[i].sa=0;  
            e[i].id=i+1;  
        }  
        for(int i=0;i<n;i++)  
        for(int j=0;j<m;j++){  
            scanf("%lf",&x);  
            e[j].sa+=x;  
        }  
        qsort(e,m,sizeof(e[0]),cmp);  
        qsort(e,k,sizeof(e[0]),cmp2);  
        for(int i=0;i<k;i++){  
            if(i)printf(" ");  
            printf("%d",e[i].id);  
        }  
        printf("\n");  
    }  
}
