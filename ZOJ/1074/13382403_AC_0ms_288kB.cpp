#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n,i,j,k,a[130][130],tmp[130];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        int mx=0;
        for(i=0;i<n;i++)
        {
            memset(tmp,0,sizeof(tmp));
            for(j=i;j<n;j++)
            {
                int dp=0;
                for(k=0;k<n;k++)
                {
                    tmp[k]+=a[j][k];
                    dp+=tmp[k];
                    if(dp>mx) mx=dp;
                    else if(dp<0) dp=0;
                }
            }
        }
        printf("%d\n",mx);
    }
    return 0;
}
