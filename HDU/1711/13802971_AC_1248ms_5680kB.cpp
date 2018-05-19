#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxm=1e4+10;
const int maxn=1e6+10;
int m,n,b[maxm],nex[maxn],a[maxn];

void getNext()
{
    int i=0,j=-1;
    nex[0]=-1;
    while(i<m)
    {
        if(j==-1||b[i]==b[j])
            nex[++i]=++j;
        else
            j=nex[j];
    }
}

int KMP()
{
    int i=0,j=0;
    getNext();
    while(i<n&&j<m)
    {
        if(j==-1||a[i]==b[j])
        {
            i++;
            j++;
        }
        else j=nex[j];
    }
    return j==m?i-m+1:-1;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<m;i++)
            scanf("%d",&b[i]);
        printf("%d\n",KMP());
    }
    return 0;
}
