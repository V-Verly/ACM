#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n,m,i,c,sum[1005]={0};
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&c);
        sum[c]++;
    }
    int mn=10005;
    for(i=1;i<=n;i++)
        if(mn>sum[i]) mn=sum[i];
    printf("%d\n",mn);
    return 0;
}
