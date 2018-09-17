#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n,ans,tot;
int a[105],res[105],p[105],last[105];

void dfs(int pos,int dep,int sum)
{
    if(pos>n||sum+p[pos]<ans) return;
    if(sum==ans)
    {
        for(int i=0;i<dep;i++)
        {
            if(i) printf("+");
            printf("%d",res[i]);
        }
        printf("\n");
        tot++;
        return;
    }
   // dfs(pos+1,dep,sum);
    for(int i=pos;i<n;i++)
    {
        res[dep]=a[i];
        dfs(i+1,dep+1,sum+a[i]);
        while(i<n&&a[i+1]==a[i]) i++;
    }
}

int main()
{
    while(scanf("%d%d",&ans,&n)!=EOF&&(ans||n))
    {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        memset(p,0,sizeof(p));
        memset(last,0,sizeof(last));
        for(int i=n-1;i>=0;i--)
            p[i]=p[i+1]+a[i];
        tot=0;
        printf("Sums of %d:\n",ans);
        dfs(0,0,0);
        if(!tot) printf("NONE\n");
    }
    return 0;
}
