#include <bits/stdc++.h>

using namespace std;

const int maxn=1e5+10;

char s[maxn],t[maxn];

class ACAutomation
{
public:
    int trie[maxn][26],cnt;
    int tag[maxn];
    int fail[maxn];
    int st[maxn],pos[maxn],cur;

    void insert(char *s)
    {
        int root=0;
        for(int i=0;s[i];i++)
        {
            int id=s[i]-'a';
            if(!trie[root][id]) trie[root][id]=++cnt;
            root=trie[root][id];
        }
        tag[root]=strlen(s);
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
        }
    }

    void query()
    {
        int root=0;
        pos[0]=0;
        for(int i=0;t[i];i++)
        {
            root=trie[pos[cur]][t[i]-'a'];
            st[++cur]=t[i]-'a';
            pos[cur]=root;
            if(tag[root])
            {
                cur-=tag[root];
                root=pos[cur];
            }
        }
        for(int i=1;i<=cur;i++) printf("%c",st[i]+'a');
        printf("\n");
    }
}AC;

int main()
{
    int n;
    scanf("%s",t);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        AC.insert(s);
    }
    AC.build();
    AC.query();
    return 0;
}
