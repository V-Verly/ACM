#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e6+10;
bool prime[maxn];
int sum[maxn];

void isprime()
{
    memset(prime,true,sizeof(prime));
    for(int i=2;i<=1e3;i++)
    {
        if(prime[i])
        {
            for(int j=i*i;j<1e6;j+=i)
                prime[j]=false;
        }
    }
}

void add()
{
    memset(sum,0,sizeof(sum));
    for(int i=2;i<maxn;i++)
    {
        sum[i]=sum[i-1];
        if(prime[i])
            sum[i]++;
    }
}

int main()
{
    int n;
    isprime();
    add();
    while(scanf("%d",&n)!=EOF)
        printf("%d\n",sum[n]);
    return 0;
}
