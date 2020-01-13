#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int change_char(char *letter,int *len)
{
    int i=0,j;
    int len_var=(*len)-1;
    if(letter[i]=='-')//如果是符号，则跳过
    {
        ++i;
        --(*len);
    }
    while(letter[i]=='0'&&i<=len_var) //去掉前面的0
    {
        --(*len);
        ++i;
    }
    for(j=0; j<=len_var; j++) //去掉小数点之后最后无效的0，从最后一位算起
    {
        if(letter[j]=='.')
        {
            while(letter[len_var]=='0'&&len_var>=0)
            {
                --(*len);
                --len_var;
            }
            break;
        }
    }
    //如果小数点后面都是无效的0.则去掉小数点
    if(letter[len_var]=='.')
        --(*len);
    return i;
}
int main()
{
    char a[100000],b[100000];
    int symbol_flag,lenght_a,lenght_b,pos_char_a,pos_char_b,out_flag=1;

    while(cin>>a>>b)
    {
        /*当两者符号不一样的时候做一个标志，
        因为存在-0=0这种情况，所以当符号不一样不能直接下定论两者不相等
        */
        if(a[0]=='-'&&b[0]!='-' || a[0]!='-'&&b[0]=='-')
            symbol_flag=1;
            
        lenght_a=strlen(a);  //求出a,b长度
        lenght_b=strlen(b);
      
        pos_char_a= change_char(a,&lenght_a);  //求出第一位不为0的数的位置
        pos_char_b= change_char(b,&lenght_b);
        if(lenght_a!=lenght_b)//当两者的有效位数不一样直接是不相等，注意下面几个continue的作用
        {
            cout<<"NO"<<endl;
            continue;
        }
        //以下几个语句都是在lenght_a=lenght_b才执行的
        if(symbol_flag==1&&lenght_a==0)//-0=0这种情况
        {
            cout<<"YES"<<endl;
            continue;
        }
        //当符号不一样，且lenght_a或者lenght_b都不为0时候是不相等的
        if(symbol_flag==1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        //当符号一样，长度相等执行下面语句，从有效长度起始位置开始判断各位是否相等
        for(int i=pos_char_a,j=pos_char_b; i<lenght_a; i++,j++)
        {
            if(a[i]!=b[j])
            {
                cout<<"NO"<<endl;
                out_flag=0;
                break;
            }
        }
        if(out_flag==1)
            cout<<"YES"<<endl;
        //从新初始化
        out_flag=1;
    }
    return 0;
}


