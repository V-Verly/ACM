#include <bits/stdc++.h>

using namespace std;

const int maxn=1e6+10;

class ACAutomation
{
public:
    int trie[maxn][26],cnt;
    int tag[maxn];
    int fail[maxn];
    bool vis[maxn];
    int st[maxn],pos[205],tot;

    void insert(char *s,int id)
    {
        int root=0;
        for(int i=0;s[i];i++)
        {
            int id=s[i]-'a';
            if(!trie[root][id]) trie[root][id]=++cnt;
            root=trie[root][id];
            tag[root]++;
        }
        pos[id]=root;
    }

    void build()
    {
        queue<int> que;
        for(int i=0;i<26;i++) if(trie[0][i]) {que.push(trie[0][i]); st[++tot]=trie[0][i]; }
        while(!que.empty())
        {
            int k=que.front(); que.pop();
            for(int i=0;i<26;i++)
            {
                if(trie[k][i])
                {
                    fail[trie[k][i]]=trie[fail[k]][i];
                    que.push(trie[k][i]);
                    st[++tot]=trie[k][i];
                }
                else trie[k][i]=trie[fail[k]][i];
            }
        }
    }

    void solve(int n)
    {
        for(int i=tot;i>0;i--) tag[fail[st[i]]]+=tag[st[i]];
        for(int i=0;i<n;i++) printf("%d\n",tag[pos[i]]);
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
        AC.insert(s,i);
    }
    AC.build();
    AC.solve(n);
    return 0;
}
