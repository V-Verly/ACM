#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n,a[70],ans,sum;
bool vis[70];

bool cmp(const int &a,const int &b)
{
    return a>b;
}

bool dfs(int cur,int len,int num)
{
    if(num>=n&&len==0)
        return true;
    int last=-1;
    for(int i=cur;i<n;i++)
    {
        if(vis[i]||a[i]==last) continue;
        vis[i]=true;
        if(len+a[i]==ans)
        {
            if(dfs(0,0,num+1)) return true;
            else last=a[i];
        }
        else if(len+a[i]<ans)
        {
            if(dfs(cur+1,len+a[i],num+1)) return true;
            else last=a[i];
        }
        vis[i]=false;
        if(len==0) break;
    }
    return false;
}

int main()
{
    while(scanf("%d",&n)!=EOF&&n)
    {
        sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        sort(a,a+n,cmp);
        memset(vis,false,sizeof(vis));
        for(ans=a[0];ans<=sum;ans++)
            if(sum%ans==0&&dfs(0,0,0)) break;
        printf("%d\n",ans);
    }
    return 0;
}
