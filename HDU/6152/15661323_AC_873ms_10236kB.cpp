#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool edge[3010][3010];
int n;

bool judge()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                if(edge[i][j]&&edge[i][k]&&edge[j][k]) return false;
    return true;
}

int main()
{
    int t,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        bool flag=true;
        memset(edge,0,sizeof edge);
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                scanf("%d",&k);
                if(k) edge[i][j]=edge[j][i]=true;
            }
        }
        if(n<=2) printf("%s\n","Great Team!");
        else printf("%s\n",judge()?"Great Team!":"Bad Team!");
    }
    return 0;
}
