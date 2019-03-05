#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e6+10,maxm=1e4+10;

int a[maxn],b[maxm];
int n,m,nex[maxm];

void getNext()
{
    int i=0,j=-1;
    nex[i]=j;
    while(i<m)
    {
        if(j==-1||b[i]==b[j]) nex[++i]=++j;
        else j=nex[j];
    }
}

int KMP()
{
    int i=0,j=0;
    getNext();
    while(i<n&&j<m)
    {
        if(j==-1||a[i]==b[j]) i++,j++;
        else j=nex[j];
        if(j==m) return i-j+1;
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<m;i++) scanf("%d",&b[i]);
        printf("%d\n",KMP());
    }
    return 0;
}
