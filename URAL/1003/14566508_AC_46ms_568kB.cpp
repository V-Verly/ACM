#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=5000+10;
int pre[maxn],val[maxn],a[2*maxn];

struct Node
{
    int l,r,val;
}node[maxn];

int Find(int x)
{
    if(x==pre[x]) return x;
    int tmp=Find(pre[x]);
    val[x]^=val[pre[x]];
    return pre[x]=tmp;
}

bool Union(int x,int y,int v)
{
    int fx=Find(x),fy=Find(y);
    if(fx==fy) return (val[x]^val[y])==v;
    pre[fx]=fy;
    val[fx]=val[x]^val[y]^v;
    return true;
}

int main()
{
    int n,m,l,r,w;
    char op[5];
    while(scanf("%d",&n)!=EOF&&n!=-1)
    {
        scanf("%d",&m);
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%s",&node[i].l,&node[i].r,op);
            node[i].val=op[0]=='o';
            node[i].l--;
            a[cnt++]=node[i].l;
            a[cnt++]=node[i].r;
        }
        sort(a,a+cnt);
        cnt=unique(a,a+cnt)-a;
        for(int i=0;i<cnt;i++)
            val[i]=0,pre[i]=i;
        int ans=0;
        for(int i=0;i<m;i++)
        {
            int x=lower_bound(a,a+cnt,node[i].l)-a;
            int y=lower_bound(a,a+cnt,node[i].r)-a;
            if(Union(x,y,node[i].val)) ans++;
            else break;
        }
        printf("%d\n",ans);
    }
    return 0;
}