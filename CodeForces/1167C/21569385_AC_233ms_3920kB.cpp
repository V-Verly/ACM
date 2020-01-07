#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 10;
int pre[maxn], sz[maxn];

int Find(int x) { return x == pre[x] ? x : pre[x] = Find(pre[x]); }

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) pre[i] = i;
    while(m --)
    {
        int t;
        scanf("%d", &t);
        if(!t) continue;
        if(t == 1) scanf("%d", &t);
        else
        {
            t --;
            int x, y;
            scanf("%d", &x);
            x = Find(x);
            while(t --)
            {
                scanf("%d", &y);
                y = Find(y);
                if(x != y) pre[y] = x;
            }
        }
    }
    for(int i = 1; i <= n; i ++) sz[Find(i)] ++;
    for(int i = 1; i <= n; i ++) printf("%d ",sz[pre[i]]);
    return 0;
}
