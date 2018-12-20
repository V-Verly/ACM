#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1000+10;
const int inf=0x3f3f3f3f;
int n,edge[maxn][maxn];

bool floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                if(edge[i][j]>edge[i][k]+edge[k][j]) edge[i][j]=edge[i][k]+edge[k][j];
            if(edge[i][i]<0) return true;
        }
    }
    return false;
}

int main()
{
    int t,m,w,s,e,l;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&w);
        memset(edge,inf,sizeof edge);
        for(int i=1;i<=n;i++) edge[i][i]=0;
        while(m--)
        {
            scanf("%d%d%d",&s,&e,&l);
            if(edge[s][e]>l) edge[s][e]=edge[e][s]=l;
        }
        while(w--)
        {
            scanf("%d%d%d",&s,&e,&l);
            edge[s][e]=-l;
        }
        printf("%s\n",floyd()?"YES":"NO");
    }
    return 0;
}
