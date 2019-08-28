#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

char s[maxn], tmp[maxn << 1];
int len[maxn << 1];

int init(char *str)
{
    int i, n = strlen(str);
    tmp[0] = '@';
    for(int i = 1; i <= 2 * n; i += 2)
    {
        tmp[i] = '#';
        tmp[i + 1] = str[i / 2];
    }
    tmp[2 * n + 1] = '#';
    tmp[2 * n + 2] = '$';
    tmp[2 * n + 3] = 0;
    return 2 * n + 1;
}

int manacher(char *str)
{
    int mx = 0, ans = 0, pos = 0;
    int n = init(str);
    for(int i = 1; i <= n; i ++)
    {
        if(mx > i) len[i] = min(mx - i, len[2 * pos - i]);
        else len[i] = 1;
        while(tmp[i - len[i]] == tmp[i + len[i]]) len[i] ++;
        if(len[i] + i > mx) mx = len[i] + i, pos = i;
    }
    return n;
}

int R[maxn << 1], L[maxn << 1];

int main()
{
    scanf("%s", s);
    int n = manacher(s), ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        if(i + (len[i] - 1) <= n) R[i + (len[i] - 1)] = max(R[i + (len[i] - 1)], len[i] - 1);
        if(i - (len[i] - 1) >= 0) L[i - (len[i] - 1)] = max(L[i - (len[i] - 1)], len[i] - 1);
    }
    for(int i = n - 1; i > 0; i --) R[i] = max(R[i], R[i + 1] - 1);
    for(int i = 2; i <= n; i ++) L[i] = max(L[i], L[i - 1] - 1);
    for(int i = 1; i <= n; i ++) if(tmp[i] == '#' && L[i] && R[i]) ans = max(ans, L[i] + R[i]);
    printf("%d\n", ans);
    return 0;
}
