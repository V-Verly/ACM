#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e6+10;
int ch[maxn][5],val[maxn],sz;

void Insert(char *s)
{
    int u=0,len=strlen(s);
    for(int i=0;i<len;i++)
    {
        int k=s[i]-'0';
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
        int k=s[i]-'0';
        if(!ch[u][k]) return 0;
        u=ch[u][k];
    }
    return val[u];
}

int main()
{
    char s[30][15];
    int t=0,count=0;
    sz=1;
    memset(ch,0,sizeof(ch));
    while(scanf("%s",s[t])!=EOF)
    {

        if(s[t][0]=='9')
        {
            bool flag=false;
            for(int i=0;i<t;i++)
            {
                //printf("%d\n",Search(s[i]));
                if(Search(s[i])>1) flag=true;
            }

            if(!flag)
                printf("Set %d is immediately decodable\n",++count);
            else
                printf("Set %d is not immediately decodable\n",++count);
            memset(ch,0,sizeof(ch));
            memset(val,0,sizeof(val));
            t=0;
            sz=1;
        }
        else
        {
            Insert(s[t]);
            t++;
        }
    }
    return 0;
}
