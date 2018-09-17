#include <iostream> 
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn=1e6+10;
bool prime[maxn];
bool perfectPrime[maxn];
int ans[maxn];

void isPrime()
{
    memset(prime,true,sizeof(prime));
    prime[1]=false;
    for(int i=2;i<=1e3;i++)
    {
        if(prime[i])
        {
            for(int j=i*i;j<=1e6;j+=i)
            {
                prime[j]=false;
            }
        }
    }
}

int sum(int x)
{
    int s=0,t;
    while(x)
    {
        t=x%10;
        x/=10;
        s+=t;
    }
    return s;
}

void isPerfectPrime()
{
    memset(perfectPrime,false,sizeof(perfectPrime));
    for(int i=2;i<=1e6;i++)
    {
        if(prime[i]&&prime[sum(i)])
            perfectPrime[i]=true;
    }
}

void add()
{
    ans[1]=0;
    for(int i=2;i<=1e6;i++)
    {
        ans[i]=ans[i-1];
        if(perfectPrime[i])
            ans[i]++;
    }
}

int main()
{
    isPrime();
    isPerfectPrime();
    add();
    int t,a,b,s,count=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        s=ans[b]-ans[a];
        if(perfectPrime[a])
            s++;
        printf("Case #%d: %d\n",++count,s);
    }
    return 0;
}