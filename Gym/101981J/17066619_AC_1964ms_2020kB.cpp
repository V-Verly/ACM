#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int n,a,t;
    long long ans=0;
    map<int,int> mp;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&t);
        a=t;
        for(int j=2;j<=a&&j*j<=t;j++)
        {
            if(a%j==0)
            {
                while(a%j==0) a/=j;
                int left=mp.count(j)?mp[j]:0;
                mp[j]=i;
                ans+=1ll*(i-left)*(n-i+1);
            }
        }
        if(a!=1)
        {
            int left=mp.count(a)?mp[a]:0;
            mp[a]=i;
            ans+=1ll*(i-left)*(n-i+1);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
