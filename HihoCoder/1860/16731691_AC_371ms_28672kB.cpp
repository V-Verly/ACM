#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e5+10;
const int M=31;
int a[maxn];

int tree[20*maxn][2],tot;
int flag[20*maxn];

void init()
{
    memset(tree,0,sizeof tree);
    memset(flag,0,sizeof flag);
    tot=0;
}

void insert_ch(int x,int p)
{
    int root=0;
    for(int i=M;i>=0;i--)
    {
        int id=(x>>i)&1;
        if(!tree[root][id]) tree[root][id]=++tot;
        root=tree[root][id];
    }
    flag[root]=p;
}

int find_ch(int x)
{
    int root=0;
    for(int i=M;i>=0;i--)
    {
        int id=(x>>i)&1;
        if(tree[root][!id]) root=tree[root][!id];
        else root=tree[root][id];
    }
    return flag[root];
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        a[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            a[i]^=a[i-1];
        }
        init();
        insert_ch(a[0],0);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int tmp=find_ch(a[i]);
            if((a[tmp]^a[i])>ans) ans=a[tmp]^a[i];
            insert_ch(a[i],i);
        }
        printf("%d\n",ans);
    }
    return 0;
}