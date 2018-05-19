#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxm=1e4+10;
const int maxn=1e6+10;

char a[maxm],b[maxn];
int nex[maxm],lena,lenb;

void getNext()
{
    int i=0,j=-1;
    nex[0]=-1;
    while(i<lena)
    {
        if(j==-1||a[i]==a[j])
            nex[++i]=++j;
        else
            j=nex[j];
    }
}

int KMP()
{
    int i=0,j=0,ans=0;
    getNext();
    while(i<lenb&&j<lena)
    {
        if(j==-1||b[i]==a[j])
        {
            i++;
            j++;
        }
        else j=nex[j];
        if(j==lena)
        {
            j=nex[j];
            ans++;
        }
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",a);
        scanf("%s",b);
        lena=strlen(a);
        lenb=strlen(b);
        printf("%d\n",KMP());
    }
    return 0;
}
