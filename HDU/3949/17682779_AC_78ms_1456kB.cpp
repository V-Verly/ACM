#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

const int MAX_BASE=63;
const int maxn=1e4+10;

int n,cnt;
ll a[maxn],b[MAX_BASE+5];
bool flag;

vector<ll> ve;

void init()
{
    memset(b,0,sizeof b);
    cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=MAX_BASE;j>=0;j--)
        {
            if(a[i]>>j&1)
            {
                if(b[j]) a[i]^=b[j];
                else
                {
                    b[j]=a[i];
                    for(int k=j-1;k>=0;k--) if(b[k]&&(b[j]>>k&1)) b[j]^=b[k];
                    for(int k=j+1;k<=MAX_BASE;k++) if(b[k]>>j&1) b[k]^=b[j];
                    break;
                }
            }
        }
    }
    ve.clear();
    for(int i=0;i<=MAX_BASE;i++) if(b[i]) { ve.push_back(b[i]); cnt++; }
}

ll query(ll k)
{
    if(cnt!=n) k--;
    if(k>=(1ll<<cnt)) return -1;
    ll ans=0;
    for(int i=0;i<ve.size();i++)
        if((k>>i)&1) ans^=ve[i];
    return ans;
}

int main()
{
    int t,q;
    ll k;
    scanf("%d",&t);
    for(int _=1;_<=t;_++)
    {
        printf("Case #%d:\n",_);
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%lld",&a[i]);
        init();
        scanf("%d",&q);
        while(q--)
        {
            scanf("%lld",&k);
            printf("%lld\n",query(k));
        }
    }
    return 0;
}
