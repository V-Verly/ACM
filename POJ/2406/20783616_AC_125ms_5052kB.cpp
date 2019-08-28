#include <cstdio>
#include <cstring>

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

int main()
{
    while(scanf("%s", a) != EOF)
    {
        if(a[0] == '.') break;
        n = strlen(a);
        getNext();
        printf("%d\n", n % (n - nex[n]) == 0 ? n / (n - nex[n]) : 1);
    }
    return 0;
}
