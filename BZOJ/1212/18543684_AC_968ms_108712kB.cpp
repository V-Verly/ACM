#include <bits/stdc++.h>

using namespace std;

const int maxn=1e6+10;

int trie[maxn][26],tot;
bool tag[maxn];
char t[maxn];

void insert_ch(char *str)
{
    int len=strlen(str),root=0;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'a';
        if(!trie[root][id]) trie[root][id]=++tot;
        root=trie[root][id];
    }
    tag[root]=true;
}

int f[maxn];

int solve(char *str)
{
    int len=strlen(str),root=0;
    memset(f,0,sizeof f);
    f[0]=1;
    for(int i=0,j;i<len;i++)
    {
        if(!f[i]) continue;
        root=0;
        for(j=i;j<len;j++)
        {
            int id=str[j]-'a';
            if(tag[root]) f[j]=1;
            if(!trie[root][id]) break;
            root=trie[root][id];
        }
        if(j==len&&tag[root]) f[j]=1;
    }
    int ans=0;
    for(int i=1;i<=len;i++) if(f[i]) ans=i;
    return ans;
}

int main()
{
    int n,m;
    char s[15];
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        insert_ch(s);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%s",t);
        printf("%d\n",solve(t));
    }
	return 0;
}
