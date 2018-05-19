#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e5+10;
int a[maxn],b[maxn];

int main()
{
    int n,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        int t=0;
        for(i=0;i<n;i++)
        {
            if(!t||a[i]<b[t-1]) b[t++]=a[i];
            else{
                for(j=0;j<=t;j++)
                {
                    if(a[i]>b[j])
                    {
                        b[j]=a[i];
                        break;
                    }
                }
            }
        }
        printf("%d\n",n-t);
    }
    return 0;
}
