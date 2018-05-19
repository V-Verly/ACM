#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn=200000+10;

int main()
{
    int n,a[maxn],i,x,y,mx=0;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        mx=max(mx,a[i]);
    }
    int flag=1;
    y=1;
    for(i=0; i<n-1; i++)
        if(abs(a[i]-a[i+1])!=1)
        {
            if(a[i]-a[i+1]) y=abs(a[i]-a[i+1]);
            break;
        }
    x=mx/y;
    if(mx%y) x++;
    for(i=0; i<n-1; i++)
    {
        int t=a[i]%y;
        if(t==0) t=y;
        if(!(t<y&&(a[i+1]-a[i])==1||t>1&&(a[i]-a[i+1])==1||abs(a[i]-a[i+1])==y))
        {
            flag=0;
            break;
        }
    }

    if(flag) {
        printf("YES\n%d %d\n",x,y);
    }
    else printf("NO\n");
    return 0;
}
