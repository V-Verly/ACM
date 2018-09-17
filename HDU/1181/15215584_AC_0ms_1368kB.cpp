#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf=0x3f3f3f3f;

bool w[26][26],vis[26];
int dis[26];

bool dijkstra()
{
    for(int i=0;i<26;i++) dis[i]=inf;
    dis[1]=0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<26;i++)
    {
        int x,m=inf;
        for(int y=0;y<26;y++) if(!vis[y]&&dis[y]<=m) m=dis[x=y];
        vis[x]=1;
        for(int y=0;y<26;y++) dis[y]=min(dis[y],dis[x]+w[x][y]);
    }
    //for(int y=0;y<26;y++) printf("%d\n",dis[y]);
    return dis[12]==0;
}

int main()
{
    char s[1005];
    int n;


    while(scanf("%s",s)!=EOF)
    {
        memset(w,inf,sizeof(w));
        n=strlen(s);
        w[s[0]-'a'][s[n-1]-'a']=0;
        if(s[0]!='0')
        {
            while(scanf("%s",s)!=EOF&&s[0]!='0')
            {
                n=strlen(s);
                w[s[0]-'a'][s[n-1]-'a']=0;
            }
        }
        printf("%s\n",dijkstra()?"Yes.":"No.");
    }

    return 0;
}
