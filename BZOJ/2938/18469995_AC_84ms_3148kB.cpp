#include <bits/stdc++.h>

using namespace std;

const int maxn=1e5+10;

class ACautomation
{
public:
    int trie[maxn][2],cnt;
    int tag[maxn];
    int fail[maxn];
    bool vis[maxn],ins[maxn];

    void insert(char *s)
    {
        int root=0;
        for(int i=0;s[i];i++)
        {
            int id=s[i]-'0';
            if(!trie[root][id]) trie[root][id]=++cnt;
            root=trie[root][id];
        }
        tag[root]=true;
    }

    void build()
    {
        queue<int> que;
        for(int i=0;i<2;i++) if(trie[0][i]) que.push(trie[0][i]);
        while(!que.empty())
        {
            int k=que.front();que.pop();
            for(int i=0;i<2;i++)
            {
                if(trie[k][i])
                {
                    fail[trie[k][i]]=trie[fail[k]][i];
                    que.push(trie[k][i]);
                }
                else trie[k][i]=trie[fail[k]][i];
            }
            tag[k]|=tag[fail[k]];
        }
    }

    bool dfs(int u)
    {
        vis[u]=true;
        ins[u]=true;
        for(int i=0;i<2;i++)
        {
            int v=trie[u][i];
            if(ins[v]) return true;
            if(vis[v]||tag[v]) continue;
            if(dfs(v)) return true;
        }
        ins[u]=false;
        return false;
    }
}AC;

char s[maxn];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        AC.insert(s);
    }
    AC.build();
    printf("%s\n",AC.dfs(0)?"TAK":"NIE");
    return 0;
}
