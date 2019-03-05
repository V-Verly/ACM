#include <bits/stdc++.h>

using namespace std;

const int maxn=605;
const int maxm=maxn*(1<<12);

struct node {int p,x; };

int n;

class ACAutomation
{
public:
    int trie[maxn][26],cnt;
    int tag[maxn];
    int fail[maxn];
    bool vis[maxn][1<<12];
    int path[maxm];
    char ch[maxm],ans[maxm];

    void insert(char *s,int id)
    {
        int root=0;
        for(int i=0;s[i];i++)
        {
            int id=s[i]-'A';
            if(!trie[root][id]) trie[root][id]=++cnt;
            root=trie[root][id];
        }
        tag[root]|=(1<<id);
    }

    void build()
    {
        queue<int> que;
        for(int i=0;i<26;i++) if(trie[0][i]) que.push(trie[0][i]);
        while(!que.empty())
        {
            int k=que.front(); que.pop();
            for(int i=0;i<26;i++)
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

    void bfs()
    {
        queue<node> que;
        que.push({0,0});
        int ed=(1<<n)-1,cur=0,tot=0;
        while(!que.empty())
        {
            node k=que.front(); que.pop();
            if(k.x==ed)
            {
                int N=0;
                for(;cur>0;cur=path[cur]) ans[N++]=ch[cur];
                for(int i=N-1;i>=0;i--) printf("%c",ans[i]);
                printf("\n");
                return;
            }
            for(int i=0;i<26;i++)
            {
                int x=trie[k.p][i];
                if(!vis[x][tag[x]|k.x])
                {
                    vis[x][tag[x]|k.x]=true;
                    que.push({x,tag[x]|k.x});
                    path[++tot]=cur;
                    ch[tot]=i+'A';
                }
            }
            cur++;
        }
    }
}AC;

int main()
{
    char s[55];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        AC.insert(s,i);
    }
    AC.build();
    AC.bfs();
    return 0;
}
