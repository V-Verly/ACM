#include <bits/stdc++.h>

using namespace std;

const int maxn=150000+10;

int de[maxn],pre[maxn],cnt[maxn];

int Find(int x) {return x==pre[x]?x:pre[x]=Find(pre[x]); }

int main()
{
    int n,m,u,v;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) pre[i]=i;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        de[u]++,de[v]++;
        int fx=Find(u),fy=Find(v);
        if(fx!=fy) pre[fx]=fy;
    }
    for(int i=1;i<=n;i++) cnt[Find(i)]++;
    for(int i=1;i<=n;i++)
        if(de[i]!=cnt[Find(i)]-1) return 0*printf("NO\n");
    printf("YES\n");
    return 0;
}