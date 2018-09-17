#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int maxn=1e6+10;

bool vis[maxn];
long long ans[maxn];
vector <long long> prime;
map<long long,long long > pos;

void isprime()
{
    memset(vis,false,sizeof(vis));
    for(long long i=2;i<=5e5;i++)
    {
        if(!vis[i])
        {
            ans[i]=i;
            prime.push_back(i);
            for(long long j=i*2;j<=1e6;j+=i)
            {
                ans[j]=i;
                vis[j]=true;
            }
        }
    }
    for(long long i=5e5;i<=1e6;i++)
    if(!vis[i])
    {

            prime.push_back(i);
            ans[i]=i;
    }
    int cnt=1;
    for(int i=0;i<prime.size();i++)
        pos[prime[i]]=cnt++;
}

int main()
{
    isprime();
    long long n;
    while(scanf("%lld",&n)!=EOF)
    {
        printf("%lld\n",pos[ans[n]]);
    }
    return 0;
}
