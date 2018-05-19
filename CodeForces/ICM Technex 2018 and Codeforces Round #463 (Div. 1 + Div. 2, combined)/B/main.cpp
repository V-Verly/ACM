#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e6+5;
int a[maxn],sum[10][maxn];

int main()
{
    int t,l,r,k,i,j,m,tmp,s;
    for(i=1;i<10;i++)
        a[i]=i;
    for(i=10;i<maxn;i++)
    {
        m=i;
        s=1;
        while(m)
        {
            tmp=m%10;
            if(tmp) s*=tmp;
            m/=10;
        }
        a[i]=a[s];
    }
    for(i=1;i<10;i++)
        sum[i][0]=0;
    for(i=1;i<maxn;i++){
        for(j=1;j<10;j++)
        {
            if(j==a[i]) sum[j][i]=sum[j][i-1]+1;
            else sum[j][i]=sum[j][i-1];
        }
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&l,&r,&k);
        printf("%d\n",sum[k][r]-sum[k][l-1]);
    }
    return 0;
}
