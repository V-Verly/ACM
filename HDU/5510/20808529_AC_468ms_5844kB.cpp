#include <bits/stdc++.h>

using namespace std;

const int maxn = 2000 + 10;

char a[510][maxn];
int nex[510][maxn];
bool vis[maxn];

void getNext(int pos)
{
    int n = strlen(a[pos]), i = 0, j = -1;
    nex[pos][i] = j;
    while(i < n)
    {
        if(j == -1 || a[pos][i] == a[pos][j]) nex[pos][++ i] = ++ j;
        else j = nex[pos][j];
    }
}

bool KMP(int x, int y)
{
    int n = strlen(a[x]), m = strlen(a[y]);
    int i = 0, j = 0;
    while(i < n && j < m)
    {
        if(j == -1 || a[x][i] == a[y][j]) i ++, j ++;
        else j = nex[y][j];
        if(j == m) return true;
    }
    return false;
}

int main()
{
    int t, n;
    scanf("%d", &t);
    for(int _ = 1; _ <= t; _ ++)
    {
        scanf("%d", &n);
        int ans = -1;
        for(int i = 1; i <= n; i ++) scanf("%s", a[i]);
        for(int i = 1; i <= n; i ++) vis[i] = false, getNext(i);
        for(int i = 2; i <= n; i ++)
        {
            bool flag = true;
            for(int j = i - 1; j > 0; j --)
            {

                if(vis[j]) continue;
                if(KMP(i, j)) vis[j] = true;
                else { ans = i; break; }
            }
        }
        printf("Case #%d: %d\n", _, ans);
    }
    return 0;
}
