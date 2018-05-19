#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=2*1e5+10;
int a[maxn];

int main()
{
    int n,i,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    sum/=2;
    int ans=0;
    for(i=0;i<n;i++)
    {
        ans+=a[i];
        if(ans>=sum) break;
    }
    printf("%d\n",i+1);
    return 0;
}
