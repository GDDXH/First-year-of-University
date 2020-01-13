#include<iostream>  
#include<ctime>  
#include<cstdlib>  
#include<cstring>  
#include<iomanip> 
using namespace std;   
const int MAX  = 1000 ;
int a[MAX][MAX];        //ͼ�ľ���  
int b[MAX];     //��¼���ڵ�Ķ�  
bool visit[MAX],ff=true;    //��¼�Ƿ񱻷��ʹ�  
int euler[MAX],ans[MAX];     //ŷ��·  
int m,n;    //  m��ʾ��������n��ʾ�ߵ�����  
int c[MAX][MAX];    //�жϸñ��Ƿ��Ѿ��߹�  
void randcreat();   //�������ͼ,��������Ķ�,���������  
void DFS(int x); //������������ж��Ƿ�Ϊ��ͨͼ  
bool judge_connect();       //�ж��Ƿ���ͨ  
int judge_euler();     //�ж��Ƿ���ŷ�����أ�·  
void find_euler(int x,int y);     //��xΪ��㿪ʼ���Ƿ����ŷ�����أ�·  
void clearmap()  
{  
    ff=true;  
    memset(b,0,MAX*sizeof(int));  
    memset(euler,-1,MAX*sizeof(int));  
    memset(c,0,MAX*sizeof(int));  
    for(int i=0;i<m;i++)  
    {  
        visit[i]=false;  
        for(int j=0;j<m;j++)  
        {  
            a[i][j]=0;  
            c[i][j]=0;  
        }  
    }  
}  
int main()  
{  
    memset(euler,-1,MAX*sizeof(int));  
    while(1)  
    {  
        cout<<"�밴˳������ڵ�ĸ����ͱߵĸ���"<<endl;  
        cin>>m>>n;  
        if(n>(m*(m-1)/2))  
        {  
            cout<<"�����������"<<endl;  
            continue;  
        }  
        randcreat();  
        if(judge_connect())  
            cout<<"����ͨͼ"<<endl;  
        else  
        {
			cout<<"������ͨͼ"<<endl;  
            clearmap();  
            continue;  
        }  
        for(int i=0;i<m;i++)  
            cout<<"����:"<<b[i]<<" ";  
        cout<<endl;  
        ff=true;  
        judge_euler();  
        /* 
        for(int j=0;j<=n;j++) 
        	cout<<setw(3)<<euler[j]; 
        cout<<endl; 
        */ 
        clearmap();  
        cout<<"***********************"<<endl<<endl;  
    }  
    return 0;  
}  
void randcreat()  
{  
    int ra,rb;  //���������  
    int count=0;    //ֻ��m���ߣ�count����¼��ǰ���ɵı���  
    srand(time(0));  
    while(count<n)  
    {  
        ra=rand()%m;  
        rb=rand()%m;  
        while(ra==rb)  
            rb=rand()%m;  
        if(!a[ra][rb])  
        {  
            a[ra][rb]=a[rb][ra]=1;  
            count++;  
            b[ra]++;  
            b[rb]++;  
        }  
    }  
    for(int i=0;i<m;i++)  
    {  
        for(int j=0;j<m;j++)  
        {
			cout<<" "<<a[i][j]<<"  ";  
        }  
        cout<<endl; 
    } 
}
void DFS(int x) //Dfs���� 
{  
    visit[x]=true;//��¼�ڵ��Ƿ񱻷��ʹ�    
    for(int i=0;i<m;i++)  
        if(!visit[i]&&a[x][i])  
            DFS(i);  
}  
bool judge_connect()  
{  
    DFS(0);  
    for(int i=0;i<m;i++)  
        if(!visit[i])  
            return false;  
    return true;  
}  
int judge_euler()  
{  
    int first=0;  //��¼�ݹ�����  
    int num=0;  //��������������  
    for(int i=0;i<m;i++)  
        if(b[i]%2)  
        {  
            first = i;  
            num++;  
        }  
    if(num==1||num>2)  
        cout<<"��ŷ��ͼ���ŷ��ͼ��"<<endl;  
    else  
    {  
        euler[0]=first;         //euler[]��¼���  
        find_euler(first,1);  
        if(num==0)  
            cout<<"ŷ��ͼ"<<endl;  
        else  
            cout<<"��ŷ��ͼ"<<endl;  
        for(int k=0;k<=n;k++)  
        {  
            cout<<setw(3)<<ans[k]+1;  
        }  
        cout<<endl<<endl;  
    }  
}  
void find_euler(int x,int y)  
{  
    if(euler[n]!=-1)  
    {  
        if(ff)  
        {  
            for(int k=0;k<=n;k++)  
                ans[k]=euler[k];  
            ff=false;  
        }  
        return ;  
    }  
    for(int i=0;i<m;i++)  
    {  
        if(a[x][i]&&!c[x][i])  
        {  
            euler[y]=i;  
            c[x][i]=c[i][x]=1;  
            find_euler(i,y+1);  
            if(!ff)     //ff������Ƿ���Ҫȡ���������ҵ�ŷ��·ֱ�ӻ���  
                return;  
            else  
                c[x][i]=c[i][x]=0;  
        }  
    }  
}  
