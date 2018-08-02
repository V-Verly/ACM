#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n,m,l[105],r[105],c1[105],c2[105];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d%d",&l[i],&r[i]);
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(int i=l[1];i<=r[1];i++)
            c1[i]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
                for(int k=l[i];k+j<=m&&k<=r[i];k++)
                    c2[j+k]+=c1[j];
            for(int j=0;j<=m;j++)
            {
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        printf("%d\n",c1[m]);
    }
    return 0;
}
