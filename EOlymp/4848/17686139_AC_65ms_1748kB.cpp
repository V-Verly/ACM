#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn=1e5+10;
int a[maxn];

int main()
{
    int n=0,x;
    while(scanf("%d",&x)!=EOF)
        a[n++]=x;
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(i) printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
    return 0;
}
