#include <bits/stdc++.h>

using namespace std;

const int maxn=5e5+10;

int trie[maxn][26],tot;
int tag[maxn],sz[maxn];
long long ans;

vector<int> son[maxn];

bool cmp(int a,int b) {return sz[a]<sz[b]; }

void insert_ch(char *str,int pos)
{
    int len=strlen(str),root=0;
    for(int i=len-1;i>=0;i--)
    {
        int id=str[i]-'a';
        if(!trie[root][id]) trie[root][id]=++tot;
        root=trie[root][id];
    }
    tag[root]=pos;
}

void build(int root,int pre)
{
    for(int i=0;i<26;i++)
    {
        if(!trie[root][i]) continue;
        if(tag[trie[root][i]])
        {
            son[pre].push_back(trie[root][i]);
            build(trie[root][i],trie[root][i]);
        }
        else build(trie[root][i],pre);
    }
}

void dfs(int root)
{
    sz[root]=1;
    for(int i=0;i<son[root].size();i++)
    {
        int v=son[root][i];
        dfs(v);
        sz[root]+=sz[v];
    }
    sort(son[root].begin(),son[root].end(),cmp);
}

int dfn[maxn],dfn_cnt;

void dfs1(int root,int pre)
{
    dfn[root]=++dfn_cnt;
    for(int i=0;i<son[root].size();i++)
    {
        int v=son[root][i];
        dfs1(v,root);
        ans+=1ll*(dfn[v]-dfn[root]);
    }
}

char s[maxn];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s);
        insert_ch(s,i);
    }
    build(0,0);
    dfs(0);
    dfs1(0,-1);
    printf("%lld\n",ans);
	return 0;
}
