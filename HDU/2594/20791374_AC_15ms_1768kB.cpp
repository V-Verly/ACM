#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1e6 + 10;

char a[maxn], b[maxn];
int nex[maxn];

void getNext()
{
    int n = strlen(a), i = 0, j = -1;
    nex[i] = j;
    while(i < n)
    {
        if(j == -1 || a[i] == a[j]) nex[++ i] = ++j;
        else j = nex[j];
    }
}

int main()
{
    while(scanf("%s%s", a, b) != EOF)
    {
        int n = strlen(a), m = strlen(b);
        for(int i = n; i < n + m; i ++) a[i] = b[i - n];
        a[n + m] = 0;
        getNext();
        int ans = nex[n + m];
        while(ans > n || ans > m) ans = nex[ans];
        if(ans == 0) puts("0");
        else
        {
            a[ans] = 0;
            printf("%s %d\n",a, ans);
        }
    }
    return 0;
}
