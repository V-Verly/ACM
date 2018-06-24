#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const long long maxn=1e6+10;
bool vis[maxn];
vector <int> prime;

void isprime()
{
    memset(vis,false,sizeof(vis));
    for(int i=2; i<=1e3; i++)
    {
        if(!vis[i])
        {
            prime.push_back(i);
            for(long long j=i*i; j<=1e6; j+=i)
                vis[j]=true;
        }
    }
    for(int i=1e3;i<=1e6;i++)
        if(!vis[i])
            prime.push_back(i);
}

int main()
{
    long long t,n,count=0;
    isprime();
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
            long long ans=1;
            for(int i=0;i<prime.size()&&prime[i]*prime[i]<=n;i++)
            {

                if(n%prime[i]==0)
                {
                    long long s=0;
                    while(n%prime[i]==0)
                    {
                        n/=prime[i];
                        s++;
                    }
                    ans*=s+1;
                }
            }
            if(n>1)
                ans*=2;
            ans--;
            printf("Case %lld: %lld\n",++count,ans);

    }
    return 0;
}