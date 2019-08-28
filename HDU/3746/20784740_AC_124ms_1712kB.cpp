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
int main()
{
    int t;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%s", a);
        n = strlen(a);
        getNext();
        int ans;
        if(nex[n] == 0) ans = n;
        else if(n % (n - nex[n]) == 0) ans = 0;
        else ans = (n - nex[n]) - n % (n - nex[n]);
        printf("%d\n", ans);
    }
    return 0;
}
