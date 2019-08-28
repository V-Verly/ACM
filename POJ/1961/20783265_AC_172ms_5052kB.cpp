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
    int _ = 1;
    while(scanf("%d", &n) != EOF && n)
    {
        scanf("%s", a);
        printf("Test case #%d\n", _ ++);
        getNext();
        for(int i = 1; i <= n; i ++) if(i % (i - nex[i]) == 0 && i != (i - nex[i]))
            printf("%d %d\n", i, i / (i - nex[i]));
        printf("\n");
    }
    return 0;
}
