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
    if(letter[i]=='-')//����Ƿ��ţ�������
    {
        ++i;
        --(*len);
    }
    while(letter[i]=='0'&&i<=len_var) //ȥ��ǰ���0
    {
        --(*len);
        ++i;
    }
    for(j=0; j<=len_var; j++) //ȥ��С����֮�������Ч��0�������һλ����
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
    //���С������涼����Ч��0.��ȥ��С����
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
        /*�����߷��Ų�һ����ʱ����һ����־��
        ��Ϊ����-0=0������������Ե����Ų�һ������ֱ���¶������߲����
        */
        if(a[0]=='-'&&b[0]!='-' || a[0]!='-'&&b[0]=='-')
            symbol_flag=1;
            
        lenght_a=strlen(a);  //���a,b����
        lenght_b=strlen(b);
      
        pos_char_a= change_char(a,&lenght_a);  //�����һλ��Ϊ0������λ��
        pos_char_b= change_char(b,&lenght_b);
        if(lenght_a!=lenght_b)//�����ߵ���Чλ����һ��ֱ���ǲ���ȣ�ע�����漸��continue������
        {
            cout<<"NO"<<endl;
            continue;
        }
        //���¼�����䶼����lenght_a=lenght_b��ִ�е�
        if(symbol_flag==1&&lenght_a==0)//-0=0�������
        {
            cout<<"YES"<<endl;
            continue;
        }
        //�����Ų�һ������lenght_a����lenght_b����Ϊ0ʱ���ǲ���ȵ�
        if(symbol_flag==1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        //������һ�����������ִ��������䣬����Ч������ʼλ�ÿ�ʼ�жϸ�λ�Ƿ����
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
        //���³�ʼ��
        out_flag=1;
    }
    return 0;
}


