#include<iostream>  
#include<ctime>  
#include<cstdlib>  
#include<cstring>  
#include<iomanip> 
using namespace std;   
const int MAX  = 1000 ;
int a[MAX][MAX];        //图的矩阵  
int b[MAX];     //记录各节点的度  
bool visit[MAX],ff=true;    //记录是否被访问过  
int euler[MAX],ans[MAX];     //欧拉路  
int m,n;    //  m表示结点个数，n表示边的条数  
int c[MAX][MAX];    //判断该边是否已经走过  
void randcreat();   //随机生成图,计算各结点的度,并输出矩阵  
void DFS(int x); //深度优先搜索判断是否为连通图  
bool judge_connect();       //判断是否联通  
int judge_euler();     //判断是否是欧拉（回）路  
void find_euler(int x,int y);     //以x为起点开始找是否存在欧拉（回）路  
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
        cout<<"请按顺序输入节点的个数和边的个数"<<endl;  
        cin>>m>>n;  
        if(n>(m*(m-1)/2))  
        {  
            cout<<"输入边数过大！"<<endl;  
            continue;  
        }  
        randcreat();  
        if(judge_connect())  
            cout<<"是连通图"<<endl;  
        else  
        {
			cout<<"不是连通图"<<endl;  
            clearmap();  
            continue;  
        }  
        for(int i=0;i<m;i++)  
            cout<<"度数:"<<b[i]<<" ";  
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
    int ra,rb;  //两个随机数  
    int count=0;    //只有m条边，count来记录当前生成的边数  
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
void DFS(int x) //Dfs遍历 
{  
    visit[x]=true;//记录节点是否被访问过    
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
    int first=0;  //记录递归的起点  
    int num=0;  //奇数度数结点个数  
    for(int i=0;i<m;i++)  
        if(b[i]%2)  
        {  
            first = i;  
            num++;  
        }  
    if(num==1||num>2)  
        cout<<"非欧拉图或半欧拉图！"<<endl;  
    else  
    {  
        euler[0]=first;         //euler[]记录结点  
        find_euler(first,1);  
        if(num==0)  
            cout<<"欧拉图"<<endl;  
        else  
            cout<<"半欧拉图"<<endl;  
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
            if(!ff)     //ff来标记是否需要取消标记如果找到欧拉路直接回退  
                return;  
            else  
                c[x][i]=c[i][x]=0;  
        }  
    }  
}  
