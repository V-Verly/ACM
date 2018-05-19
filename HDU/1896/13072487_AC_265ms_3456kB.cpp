#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct Stone
{
    int p,d;
    bool operator <(const Stone &t) const
    {
        if(p==t.p) return d>t.d;
        return p>t.p;
    }
};

int main()
{
    int t,n,i;
    Stone a;
    scanf("%d",&t);
    while(t--)
    {
        priority_queue <Stone> road;
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d%d",&a.p,&a.d);
            road.push(a);
        }
        int ans=1;
        Stone k;
        while(!road.empty())
        {
            k=road.top();
            road.pop();
            if(ans%2)
            {
                k.p+=k.d;
                road.push(k);
            }
            ans++;
        }
        printf("%d\n",k.p);
    }
    return 0;
}
