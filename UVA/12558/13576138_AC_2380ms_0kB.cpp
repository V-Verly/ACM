#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

const int maxn=1e5+10;
int maxd;
long long ans[maxn],v[maxn];
set <long long> s;

long long gcd(long long a,long long b)
{
    return b?gcd(b,a%b):a;
}

long long get_first(long long a,long long b)
{
    return b/a+1;
}

bool better(int d)
{
    for(int i=d; i>=0; i--)
        if(v[i]!=ans[i])
            return ans[i]==-1||v[i]<ans[i];
    return false;
}

bool dfs(int d,long long from,long long aa,long long bb)
{
    if(d==maxd)
    {
        if(bb%aa) return false;
        v[d]=bb/aa;
        if(s.count(bb/aa)) return false;
        if(better(d))
        {
            memcpy(ans,v,sizeof(long long)*(d+1));
        }
        return true;
    }
    bool ok=false;
    from=max(from,get_first(aa,bb));
    for(int i=from;;i++)
    {
        if(bb*(maxd+1-d)<=i*aa) break;
        if(s.count(i)) continue;
        v[d]=i;
        long long b2=bb*i;
        long long a2=aa*i-bb;
        long long g=gcd(a2,b2);
        if(dfs(d+1,i+1,a2/g,b2/g)) ok=true;
    }
    return ok;
}

int main()
{
    int t,a,b,k,count=0;
    long long m;
    scanf("%d",&t);
    while(t--)
    {
        s.clear();
        scanf("%d%d%d",&a,&b,&k);
        while(k--)
        {
            scanf("%lld",&m);
            s.insert(m);
        }
        printf("Case %d: %d/%d=",++count,a,b);
        int ok=0;
        for(maxd=1;;maxd++)
        {
            memset(ans,-1,sizeof(ans));
            if(dfs(0,get_first(a,b),a,b))
            {
                ok=1;

                break;
            }
        }
        for(int i=0;i<=maxd;i++)
        {
            if(i) printf("+");
            printf("1/%lld",ans[i]);
        }

        printf("\n");
    }

    return 0;
}
