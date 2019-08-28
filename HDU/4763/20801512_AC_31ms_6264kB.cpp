#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 10;

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

bool KMP(char a[], char b[], int n, int m)
{
    int i = 0, j = 0;
    while(i < n && j < m)
    {
        if(j == -1 || a[i] == b[j]) i ++, j ++;
        else j = nex[j];
        if(j == m) return true;
    }
    return false;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%s", a);
        n = strlen(a);
        getNext();
        int ans = nex[n];
        while(ans)
        {
            if(n >= 3 * ans && KMP(a + ans, a, n - 2 * ans, ans)) break;
            ans = nex[ans];
        }
        printf("%d\n", ans);
    }
    return 0;
}
