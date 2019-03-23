#include <bits/stdc++.h>

using namespace std;



int main()
{
    int t;
    long long n,m,v,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld%lld",&n,&m,&v,&k);
        if(m>=n)
        {
            printf("0\n");
            continue;
        }
        if((m-v)*k<=m)
        {
            printf("-1\n");
            continue;
        }
        int cnt=0;
        while(m<n)
        {
            m=(m-v)*k;
            cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
