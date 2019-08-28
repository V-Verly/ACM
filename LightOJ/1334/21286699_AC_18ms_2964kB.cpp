#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e4 + 10;
char s[maxn], t[maxn];
int nex[maxn], dp[maxn], l[maxn], r[maxn];

void getNext()
{
    int n = strlen(t), i = 0, j = -1;
    nex[i] = j;
    while(i < n)
    {
        if(j == -1 || t[i] == t[j]) nex[++ i] = ++ j, dp[i] = dp[j] + 1;
        else j = nex[j];
    }
}

void KMP(int a[])
{
    int n = strlen(s), m = strlen(t), i = 0, j = 0;
    getNext();
    while(i < n)
    {
        if(j == -1 || s[i] == t[j]) i ++, j ++, a[i] = dp[j];
        else j = nex[j];
        if(j == m) a[i] --, j = nex[j];
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int _ = 1; _ <= T; _ ++)
    {

        scanf("%s%s", s, t);
        int n = strlen(s), m = strlen(t);
        KMP(l);
        reverse(s, s + n);
        reverse(t, t + m);
        KMP(r);
        long long res = 0;
        for(int i = 1; i <= n; i ++)  res += 1ll * l[i] * r[n - i];
        printf("Case %d: %lld\n", _, res);
    }
    return 0;
}
