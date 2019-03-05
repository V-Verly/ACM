#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=2e6+10;

char s[1010][25];

int trie[maxn][30],tot;
int cnt[maxn];

void insert(char *str)
{
    int len=strlen(str);
    int root=0;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'a';
        if(!trie[root][id]) trie[root][id]=++tot;

        root=trie[root][id];
        cnt[root]++;
    }
}

void find(char *str)
{
    int len=strlen(str);
    int root=0;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'a';
        if(cnt[root]==1) return;
        printf("%c",str[i]);
        root=trie[root][id];
    }
}


int main()
{
    int n=0;
    while(~scanf("%s",s[n]))
    {
        insert(s[n]);
        n++;
    }
    for(int i=0;i<n;i++)
    {
        printf("%s ",s[i]);
        find(s[i]);
        printf("\n");
    }
    return 0;
}
