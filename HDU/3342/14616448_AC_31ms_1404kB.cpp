#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n,m,u,v;
    int mp[105][105],inde[105];
    while(scanf("%d%d",&n,&m)!=EOF&&(n||m))
    {
        memset(mp,0,sizeof(mp));
        memset(inde,0,sizeof(inde));
        while(m--)
        {
            scanf("%d%d",&u,&v);
            if(!mp[u][v]) inde[v]++;
            mp[u][v]++;
        }
        bool flag=true;
        for(int cnt=0;cnt<n;cnt++)
        {
            for(u=0;u<n;u++)
            {
                if(!inde[u])
                {
                    inde[u]--;
                    for(v=0;v<n;v++)
                        if(mp[u][v])
                            inde[v]--;
                    break;
                }
            }
            if(u==n) flag=false;
        }
        printf("%s\n",flag?"YES":"NO");
    }
    return 0;
}
