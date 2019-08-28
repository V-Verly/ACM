#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1e6 + 10;
const int mod = 10007;

char a[maxn];
int n, nex[maxn];

void getNext()
{
    int i = 0, j = -1;
    nex[i] = j;
    while(i < n)
    {
        if(j == -1 || a[i] == a[j]) nex[++ i] = ++ j;
        else j = nex[j];
    }
}

int dp[maxn];

int main()
{
    int t;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d%s", &n, a);
        getNext();
        int ans = 0;
        for(int i = 1; i <= n; i ++) dp[i] = 1;
        for(int i = n; i > 0; i --) (dp[nex[i]] += dp[i]) % mod;
        for(int i = 1; i <= n; i ++) (ans += dp[i]) %= mod;
        printf("%d\n", ans);
    }
    return 0;
}
