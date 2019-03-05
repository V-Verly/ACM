#include <bits/stdc++.h>

using namespace std;

const int mod=10007;
const int maxn=10000;

class ACAutomation
{
public:
    int trie[maxn][26],cnt;
    bool tag[maxn];
    int fail[maxn];
    int f[105][maxn];

    void init()
    {
        memset(trie,0,sizeof trie);
        memset(tag,0,sizeof tag);
        memset(fail,0,sizeof fail);
        cnt=0;
    }

    void insert(char *s)
    {
        int root=0;
        for(int i=0;s[i];i++)
        {
            int id=s[i]-'A';
            if(!trie[root][id]) trie[root][id]=++cnt;
            root=trie[root][id];
        }
        tag[root]=true;
    }

    void build()
    {
        queue<int> que;
        for(int i=0;i<26;i++) if(trie[0][i]) que.push(trie[0][i]);
        while(!que.empty())
        {
            int k=que.front();que.pop();
            for(int j=0;j<26;j++)
            {
                if(trie[k][j])
                {
                    fail[trie[k][j]]=trie[fail[k]][j];
                    que.push(trie[k][j]);
                }
                else trie[k][j]=trie[fail[k]][j];

            }
            if(tag[fail[k]]) tag[k]=true;
        }
    }

    int dp(int m)
    {
        f[0][0]=1;
        for(int i=0;i<m;i++)
        {
            for(int p=0;p<=cnt;p++)
            {
                if(tag[p]) continue;
                for(int j=0;j<26;j++)
                {
                    int k=trie[p][j];
                    (f[i+1][k]+=f[i][p])%=mod;
                }
            }
        }
        int ans=0;
        for(int i=0;i<=cnt;i++) if(!tag[i]) (ans+=f[m][i])%=mod;
        return ans;
    }
}AC;

int main()
{
    int n,m;
    char s[105];
    scanf("%d%d",&n,&m);
    AC.init();
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        AC.insert(s);
    }
    AC.build();
    int sum=1;
    for(int i=0;i<m;i++) (sum*=26)%=mod;
    printf("%d\n",(sum-AC.dp(m)+mod)%mod);
    return 0;
}
