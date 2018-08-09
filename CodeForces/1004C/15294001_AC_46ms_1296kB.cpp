#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e5+10;
int a[maxn],pre[maxn],pos[maxn];
bool vis[maxn];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    memset(vis,false,sizeof(vis));
    memset(pos,0,sizeof(pos));
    //vis[a[n-1]]=true;
    //pos[n-1]=1;
    for(int i=n-1;i>=0;i--)
    {
        pos[i]=pos[i+1]+(!vis[a[i]]);
        vis[a[i]]=true;
    }
    long long ans=0;
    memset(vis,false,sizeof(vis));
    for(int i=0;i<n;i++)
    {
        if(!vis[a[i]])
        {
            ans+=pos[i+1];
            vis[a[i]]=true;
        }
    }
    printf("%lld\n",ans);
    return 0;
}