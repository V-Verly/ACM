#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e6+10;
int ch[maxn][30],val[maxn]={0},sz;

void insert(char *s)
{
    int u=0,len=strlen(s);
    for(int i=0;i<len;i++)
    {
        int k=s[i]-'a';
        if(!ch[u][k])
            ch[u][k]=sz++;
        val[ch[u][k]]++;
        u=ch[u][k];
    }
}

int Search(char *s)
{
    int u=0,len=strlen(s);
    for(int i=0;i<len;i++)
    {
        int k=s[i]-'a';
        if(!ch[u][k]) return 0;
        u=ch[u][k];
    }
    return val[u];
}

int main()
{
    char s[15];
    memset(ch[0],0,sizeof(ch[0]));
    sz=1;
    while(gets(s)!=NULL)
    {
        if(strlen(s)==0) break;
        insert(s);
    }
    while(scanf("%s",s)!=EOF)
        printf("%d\n",Search(s));
    return 0;
}
