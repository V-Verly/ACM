#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=5e6+10;
int euler[maxn];
unsigned long long sum[maxn]={0};

void init()
{
    for(int i=1;i<maxn;i++)
        euler[i]=i;
    for(int i=2;i<maxn;i++)
    {
        if(euler[i]==i)
        {
            for(int j=i;j<maxn;j+=i)
                euler[j]=euler[j]/i*(i-1);
        }
    }
    for(int i=1;i<maxn;i++)
        sum[i]=sum[i-1]+ (unsigned long long)euler[i]*euler[i];
}

int main()
{
    init();
    int t,l,r;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d%d",&l,&r);
        printf("Case %d: %llu\n",i,sum[r]-sum[l-1]);
    }
    return 0;
}