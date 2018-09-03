#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e6+10;
const int mod=1e9+7;

char a[maxn],b[maxn],tmp[maxn];

int nex[maxn];
long long ex[maxn]; //ex数组即为extend数组
//预处理计算nex数组
void GETnex(char *str)
{
    int i=0,j,po,len=strlen(str);
    nex[0]=len;//初始化nex[0]
    while(str[i]==str[i+1]&&i+1<len)//计算nex[1]
        i++;
    nex[1]=i;
    po=1;//初始化po的位置
    for(i=2; i<len; i++)
    {
        if(nex[i-po]+i<nex[po]+po)//第一种情况，可以直接得到nex[i]的值
            nex[i]=nex[i-po];
        else//第二种情况，要继续匹配才能得到nex[i]的值
        {
            j=nex[po]+po-i;
            if(j<0)j=0;//如果i>po+nex[po],则要从头开始匹配
            while(i+j<len&&str[j]==str[j+i])//计算nex[i]
                j++;
            nex[i]=j;
            po=i;//更新po的位置
        }
    }
}
//计算extend数组
void EXKMP(char *s1,char *s2)
{
    int i=0,j,po,len=strlen(s1),l2=strlen(s2);
    GETnex(s2);//计算子串的nex数组
    while(s1[i]==s2[i]&&i<l2&&i<len)//计算ex[0]
        i++;
    ex[0]=i;
    po=0;//初始化po的位置
    for(i=1; i<len; i++)
    {
        if(nex[i-po]+i<ex[po]+po)//第一种情况，直接可以得到ex[i]的值
            ex[i]=nex[i-po];
        else//第二种情况，要继续匹配才能得到ex[i]的值
        {
            j=ex[po]+po-i;
            if(j<0)j=0;//如果i>ex[po]+po则要从头开始匹配
            while(i+j<len&&j<l2&&s1[j+i]==s2[j])//计算ex[i]
                j++;
            ex[i]=j;
            po=i;//更新po的位置
        }
    }
}

long long Pow(long long a,long long n=mod-2)
{
    long long ans=1,base=a;
    while(n)
    {
        if(n&1) (ans*=base)%=mod;
        (base*=base)%=mod;
        n>>=1;
    }
    return ans;
}

int main()
{
    int t;
    long long ans;
    scanf("%d",&t);
    long long inv=Pow(2);
    while(t--)
    {
        scanf("%s%s",a,b);
        int n=strlen(a),m=strlen(b);
        for(int i=0;i<n;i++)
            tmp[i]=a[n-i-1];
        tmp[n]=0;
        strcpy(a,tmp);
        for(int i=0;i<m;i++)
            tmp[i]=b[m-i-1];
        tmp[m]=0;
        strcpy(b,tmp);
        EXKMP(a,b);
        ans=0;
        for(int i=0;i<n;i++)
        {
            (ans+=ex[i]%mod*(ex[i]+1)%mod*inv%mod)%=mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
