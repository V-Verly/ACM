#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e6+10;

char a[maxn],b[maxn];
int nex[maxn];

void getNext()
{
    int n=strlen(a),i=0,j=-1;
    nex[i]=j;
    while(i<n)
    {
        if(j==-1||a[i]==a[j]) nex[++i]=++j;
        else j=-1;
    }
}

int KMP()
{
    int n=strlen(a),m=strlen(b);
    int i=0,j=0,ans=0;
    getNext();
    while(i<n&&j<m)
    {
        if(i==-1||a[i]==b[j]) i++,j++;
        else i=nex[i];
        if(i==n) i=nex[i],ans++;
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",a,b);
        printf("%d\n",KMP());
    }
    return 0;
}
