#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn=20000+10;
bool prime[maxn];
int ans[maxn];

void isprime()
{
    memset(prime,true,sizeof(prime));
    for(int i=2; i<=sqrt(20000); i++)
    {
        if(prime[i])
        {
            for(int j=i*i; j<=20000; j+=i)
                prime[j]=false;
        }
    }
}

void decompose()
{
    memset(ans,0,sizeof(ans));
    ans[1]=1;
    for(int i=2; i<=20000; i++)
    {
        int t=i;
        for(int j=2; j<=t; j++)
        {

            if(t%j==0&&prime[j])
            {
                t/=j;
                ans[i]=j;
            }
        }
    }
}

int main()
{
    int t,n,mx;
    isprime();
    decompose();
    while(~scanf("%d",&t))
    {
        scanf("%d",&mx);
        t--;
        while(t--)
        {
            scanf("%d",&n);
            if(ans[n]>ans[mx])
                mx=n;
        }
        printf("%d\n",mx);
    }

    return 0;
}