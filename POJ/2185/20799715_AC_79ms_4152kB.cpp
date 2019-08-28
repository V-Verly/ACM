#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 10000 + 10;

char grid[maxn][80];
int n, m;
int rnex[maxn][80], cnex[maxn];
int rlen[maxn], cnt[80];
int ans1, ans2;

void r_getNext(int r, char *str)
{
    int i = 0, j = -1;
    rnex[r][i] = j;
    while(i < m)
    {
        if(j == -1 || str[i] == str[j]) rnex[r][++ i] = ++ j;
        else j = rnex[r][j];
    }
    rlen[r] = m - rnex[r][m];
    for(i = rlen[r]; i <= m; i += rlen[r]) cnt[i] ++;
    i -= rlen[r];
    for(int j = i + 1; j <= m; j ++)
    {
        int x = 0, y = j;
        while(str[x] == str[y]) x ++, y ++;
        if(y == m) cnt[j] ++;
    }
}

void c_getNext()
{
    int i = 0, j = -1;
    cnex[i] = j;
    while(i < n)
    {
        if(j == -1 || strcmp(grid[i], grid[j]) == 0) cnex[++ i] = ++ j;
        else j = cnex[j];
    }
    ans2 = n - cnex[n];
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i ++) scanf("%s", grid[i]);
    for(int i = 0; i < n; i ++) r_getNext(i, grid[i]);
    c_getNext();
    for(int i = 1; i <= m; i ++) if(cnt[i] == n)
    {
        ans1 = i;
        break;
    }
    printf("%d\n", ans1 * ans2);
    return 0;
}
