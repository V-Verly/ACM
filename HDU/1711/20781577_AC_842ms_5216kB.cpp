#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1e6 + 10;

int a[maxn], b[maxn], n, m;
int nex[maxn];

void getNext()
{
    int i = 0, j = -1;
    nex[i] = j;
    while(i < m)
    {
        if(j == -1 || b[i] == b[j]) nex[++ i] = ++ j;
        else j = -1;
    }
}

int KMP()
{
    getNext();
    int i = 0, j = 0;
    while(i < n && j < m)
    {
        if(j == -1 || a[i] == b[j]) i ++, j ++;
        else j = nex[j];
        if(j == m) return i - m + 1;
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
        for(int i = 0; i < m; i ++) scanf("%d", &b[i]);
        printf("%d\n", KMP());
    }
    return 0;
}
