#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Ore
{
    ll x;
    int val;
    bool operator<(const Ore &o) const
    {
        return val>o.val;
    }
} ore[1005];

int n;

void cal()
{
    ll b[63];
    memset(b,0,sizeof b);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=63;j>=0;j--)
        {
            if(ore[i].x>>j&1)
            {
                if(b[j]) ore[i].x^=b[j];
                else
                {

                    b[j]=ore[i].x;
                    for(int k=j-1;k>=0;k--) if(b[k]&&(b[j]>>k&1)) b[j]^=b[k];
                    for(int k=j+1;k<=63;k++) if(b[k]>>j&1) b[k]^=b[j];
                    ans+=ore[i].val;
                    break;
                }
            }
        }
    }
    printf("%d\n",ans);
}

int main()
{

    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld%d",&ore[i].x,&ore[i].val);
    sort(ore,ore+n);
    cal();
    return 0;
}
