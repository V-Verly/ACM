#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=5e5+10;

int trie[maxn][10],tot;
int tag[maxn];

char s[maxn];

bool insert_ch(char *str)
{
	int root=0,len=strlen(str);
	bool res=false;
	for(int i=0;i<len;i++)
	{
		int id=str[i]-'0';
		if(tag[root]) res=true;
		if(i==len-1&&trie[root][id]) res=true;
		if(!trie[root][id]) trie[root][id]=++tot;
		root=trie[root][id];
	}
	tag[root]=true;
	return res;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		bool ans=false;
		memset(trie,0,sizeof trie);
		memset(tag,0,sizeof tag);
		tot=0;
		for(int i=0;i<n;i++)
		{
			scanf("%s",s);
			ans|=insert_ch(s);
		}
		printf("%s\n",!ans?"YES":"NO");
	}
	return 0;
}
