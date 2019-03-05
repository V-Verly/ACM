#include <bits/stdc++.h>

using namespace std;

const int maxn=1e7+10;

char s[105],t[maxn];
int n,m;

class ACAutomation
{
public:
    int trie[maxn][4],cnt;
    int dep[maxn],ans[maxn];
    int fail[maxn];
    bool vis[maxn];
    vector<int> e[maxn];

    int id(char x)
    {
        if(x=='S') return 0;
        if(x=='E') return 1;
        if(x=='N') return 2;
        if(x=='W') return 3;
    }

    void insert(char *s,int x)
    {
        int root=0;
        for(int i=0;s[i];i++)
        {
            int pos=id(s[i]);
            if(!trie[root][pos])
            {
                trie[root][pos]=++cnt;
                dep[cnt]=i+1;
            }
            root=trie[root][pos];
            e[root].push_back(x);
        }
    }

    void build()
    {
        queue<int> que;
        for(int i=0;i<4;i++) if(trie[0][i]) que.push(trie[0][i]);
        while(!que.empty())
        {
            int k=que.front(); que.pop();
            for(int i=0;i<4;i++)
            {
                if(trie[k][i])
                {
                    fail[trie[k][i]]=trie[fail[k]][i];
                    que.push(trie[k][i]);
                }
                else trie[k][i]=trie[fail[k]][i];
            }
        }
    }

    void solve()
    {
        int root=0;
        for(int i=0;t[i];i++)
        {
            int pos=id(t[i]);
            root=trie[root][pos];
            for(int j=root;j&&!vis[j];j=fail[j])
            {
                vis[j]=true;
                for(int k=0;k<e[j].size();k++)
                {
                    int r=e[j][k];
                    ans[r]=max(ans[r],dep[j]);
                }
            }
        }
        for(int i=0;i<n;i++) printf("%d\n",ans[i]);
    }
}AC;

int main()
{
    scanf("%d%d",&m,&n);
    scanf("%s",t);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        AC.insert(s,i);
    }
    AC.build();
    AC.solve();
    return 0;
}
