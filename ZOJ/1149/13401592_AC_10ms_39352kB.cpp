#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=5*1e6+10;
int v[maxn],w[maxn];

int main()
{
    int a[6],c,i,dp[60005],count=0;
    while(scanf("%d",&a[0])!=EOF)
    {
        memset(dp,0,sizeof(dp));
        c=a[0];
        for(i=1;i<6;i++)
        {
            scanf("%d",&a[i]);
            c+=a[i]*(i+1);
        }
        if(!c) break;
        bool flag=false;
        if(c%2==0)
        {
            c/=2;
            int ans=0;
            for(i=0;i<6;i++)
            {
                for(int j=1;j<=a[i];j<<=1)
                {
                    v[ans]=j*(i+1);
                    w[ans++]=j*(i+1);
                    a[i]-=j;
                }
                if(a[i]>0)
                {
                    v[ans]=a[i]*(i+1);
                    w[ans++]=a[i]*(i+1);
                }
            }
            for(i=0;i<ans;i++)
            {
                for(int j=c;j>=w[i];j--)
                {
                    dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
                    //printf("%d\n",dp[c]);
                    if(dp[c]==c) {flag=true;break;}
                }
            }
        }
        printf("Collection #%d:\n",++count);
        if(flag)
            printf("Can be divided.\n");
        else
            printf("Can't be divided.\n");
        printf("\n");
    }
    return 0;
}
