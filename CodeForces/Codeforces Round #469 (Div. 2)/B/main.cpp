#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100000+10;
int x[maxn],y[maxn];
int se(int l,int r,int a)
{
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(a<y[mid])
            r=mid-1;
        else if(a>y[mid])
            l=mid+1;
        else {return mid;}
    }

    return -1;
}
int main()
{
    int m,n,i;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++){
        scanf("%d",&x[i]);
        if(i) x[i]+=x[i-1];
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&y[i]);
        if(i) y[i]+=y[i-1];

    }

    int ans=0,j=0,sum=0;
    for(i=0;i<m;i++)
    {
        if(se(j,n,x[i])!=-1) {ans++;
        j=se(j,n,x[i]);
        }
    }
    printf("%d\n",ans);
    return 0;
}
