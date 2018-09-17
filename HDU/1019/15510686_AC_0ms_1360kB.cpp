#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int ans,x;
        scanf("%d",&ans);
        n--;
        while(n--)
        {
            scanf("%d",&x);
            ans=ans/__gcd(ans,x)*x;
        }
        printf("%d\n",ans);
    }
    return 0;
}
