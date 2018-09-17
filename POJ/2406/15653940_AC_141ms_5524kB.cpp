#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e6+10;
char a[maxn];
int nex[maxn],len;

void getNext()
{
    int i=0,j=-1;
    nex[0]=-1;
    while(i<len)
    {
        if(j==-1||a[i]==a[j]) nex[++i]=++j;
        else j=nex[j];
    }
}

int main()
{
    while(scanf("%s",a)!=EOF&&a[0]!='.')
    {
        len=strlen(a);
        getNext();
        if(len%(len-nex[len])==0&&nex[len]) printf("%d\n",len/(len-nex[len]));
        else printf("1\n");
    }
    return 0;
}
