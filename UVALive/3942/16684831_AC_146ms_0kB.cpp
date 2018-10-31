#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=3e5+10;
const int mod=20071027;

char s[maxn];
int dp[maxn],len;

int trie[maxn][30],tot;
bool val[maxn];

void insert_ch(char *str)
{
	int len=strlen(str);
	int root=0;
	for(int i=0;i<len;i++)
	{
		int id=str[i]-'a';
		if(!trie[root][id]) trie[root][id]=++tot;
		root=trie[root][id];
	}
	val[root]=true;
}

void find_ch(char *str,int pos)
{
	int root=0,ans=0;
	for(int i=pos;i<len&&i<=pos+100;i++)
	{
		int id=str[i]-'a';
		if(!trie[root][id]) return;
		root=trie[root][id];
		if(val[root]) (dp[pos]+=dp[i+1])%=mod;
	}
}

void init()
{
    memset(trie,0,sizeof trie);
	memset(val,0,sizeof val);
	memset(dp,0,sizeof dp);
	tot=0;
}

int main()
{
    char t[105];
    int n,cnt=0;
    while(scanf("%s",s)!=EOF)
    {
        init();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",t);
            insert_ch(t);
        }
        len=strlen(s);
        dp[len]=1;
        for(int i=len-1;i>=0;i--) find_ch(s,i);
        printf("Case %d: %d\n",++cnt,dp[0]);
    }
    return 0;
}
