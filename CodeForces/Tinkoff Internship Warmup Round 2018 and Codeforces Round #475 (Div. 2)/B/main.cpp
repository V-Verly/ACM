#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n,a,b,c,t,ans=0,time,s[1005];
    scanf("%d%d%d%d%d",&n,&a,&b,&c,&t);
    for(int i=0;i<n;i++)
        scanf("%d",&s[i]);
    for(int i=0;i<n;i++)
    {
        if(b<c) ans+=a+(c-b)*(t-s[i]);
        else ans+=a;
    }
    printf("%d\n",ans);
    return 0;
}
