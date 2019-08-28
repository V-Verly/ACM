#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 10;

char a[maxn], b[maxn];
int n, nex[maxn];

void getNext()
{
    int i = 0, j = -1;
    nex[i] = j;
    while(i < n)
    {
        if(j == -1 || b[i] == b[j]) nex[++ i] = ++ j;
        else j = nex[j];
    }
}

int KMP()
{
    int i = 0, j = 0;
    getNext();
    while(i < n && j < n)
    {
        if(j == -1 || a[i] == b[j]) i ++, j ++;
        else j = nex[j];
        if(i == n) return j;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int _ = 1; _ <= t; _ ++)
    {
        scanf("%s", a);
        n = strlen(a);
        reverse_copy(a, a + n, b);
        printf("Case %d: %d\n", _, 2 * n - KMP());
    }
    return 0;
}
