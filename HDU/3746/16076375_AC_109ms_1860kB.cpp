#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e5+10;
char a[maxn];
int nex[maxn],len;

void getNext()
{
    int i=0,j=-1;
    nex[0]=-1;
    while(i<len)
    {
        if(j==-1||a[i]==a[j])
            nex[++i]=++j;
        else j=nex[j];
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",a);
        len=strlen(a);
        getNext();
        int cyclic=len-nex[len];
        if(len!=cyclic&&len%cyclic==0) printf("0\n");
        else printf("%d\n",cyclic-len%cyclic);
    }
    return 0;
}
