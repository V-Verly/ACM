#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const int maxn=2e7+10;
bool vis[maxn];
int prime[3000000],cnt=0;

vector<int> dis[155];

void isprime()
{
    memset(vis,true,sizeof(vis));
    for(int i=2;i*i<=2e7;i++)
    {
        if(vis[i])
        {
            //prime.push_back(i);
            for(int j=i*i;j<=2e7;j+=i)
                vis[j]=false;
        }
    }
    //printf("%d\n",vis[8]);
    for(int i=2;i<=2e7;i++)
        if(vis[i]) prime[cnt++]=i;
   // printf("%d\n",prime.size());
    for(int i=1;i<cnt;i++)
        if(prime[i]-prime[i-1]<=150) dis[prime[i]-prime[i-1]].push_back(prime[i]);
}

int judge(int a,int b)
{
    if(a>b) swap(a,b);
    int k=b-a;
   // if(!k) return 0;
    for(int i=0;i<dis[k].size();i++)
        if(b<=dis[k][i]) return dis[k][i]-b;
    return -1;
}

int main()
{
    int t,a,b;
    isprime();
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d%d",&a,&b);
        printf("Case %d: %d\n",i,judge(a,b));
    }
    return 0;
}
