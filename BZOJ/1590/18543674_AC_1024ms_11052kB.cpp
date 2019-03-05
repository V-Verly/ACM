#include <bits/stdc++.h>

using namespace std;

const int maxn=5e5+10;

int trie[maxn][2],tot;
int cnt[maxn],a[maxn],tag[maxn];

void insert_ch(int n)
{
    int root=0;
    for(int i=0;i<n;i++)
    {
        int id=a[i];
        if(!trie[root][id]) trie[root][id]=++tot;
        root=trie[root][id];
        cnt[root]++;
    }
    tag[root]++;
}

int solve(int n)
{
    int ans=0,root=0;
    for(int i=0;i<n;i++)
    {
        int id=a[i];
        ans+=tag[root];
        if(!trie[root][id]) return ans;
        root=trie[root][id];
    }
    ans+=cnt[root];
    return ans;
}

int main()
{
    int n,m,t;
    scanf("%d%d",&n,&m);
    while(n--)
    {
        scanf("%d",&t);
        for(int i=0;i<t;i++) scanf("%d",&a[i]);
        insert_ch(t);
    }
    while(m--)
    {
        scanf("%d",&t);
        for(int i=0;i<t;i++) scanf("%d",&a[i]);
        printf("%d\n",solve(t));
    }
	return 0;
}
