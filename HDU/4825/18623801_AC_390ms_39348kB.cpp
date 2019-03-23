#include <bits/stdc++.h>

using namespace std;

const int maxn=1e5+10;

int trie[32*maxn][2],tot;
int tag[32*maxn];

int a[maxn];

void init()
{
    memset(trie,0,sizeof trie);
    memset(tag,0,sizeof tag);
    tot=0;
}

void insert_ch(int x,int pos)
{
    int root=0;
    for(int i=31;i>=0;i--)
    {
        int id=(x>>i)&1;
        if(!trie[root][id]) trie[root][id]=++tot;
        root=trie[root][id];
    }
    tag[root]=pos;
}

int find_ch(int x)
{
    int root=0;
    for(int i=31;i>=0;i--)
    {
        int id=!((x>>i)&1);
        if(!trie[root][id]) root=trie[root][!id];
        else root=trie[root][id];
    }
    return tag[root];
}

int main()
{
    int t,n,q,k;
    scanf("%d",&t);
    for(int _=1;_<=t;_++)
    {
        init();
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            insert_ch(a[i],i);
        }
        printf("Case #%d:\n",_);
        while(q--)
        {
            scanf("%d",&k);
            int pos=find_ch(k);
            printf("%d\n",a[pos]);
        }
    }
    return 0;
}
