#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n,m,u,v;
    int mp[505][505],inde[505];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(inde,0,sizeof(inde));
        memset(mp,0,sizeof(mp));
        while(m--)
        {
            scanf("%d%d",&u,&v);
            if(!mp[u][v]) inde[v]++;
            mp[u][v]=1;
        }
        for(int cnt=0;cnt<n;cnt++)
        {
            for(int u=1;u<=n;u++)
            {
                if(!inde[u])
                {
                    if(cnt) printf(" ");
                    printf("%d",u);
                    inde[u]--;
                    for(int v=1;v<=n;v++)
                    {
                        if(mp[u][v])
                            inde[v]--;
                    }
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
