#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=4e5+10;
char a[maxn];
int nex[maxn],ans[maxn],len;

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
    while(scanf("%s",a)!=EOF)
    {
        len=strlen(a);
        int cnt=0;
        int t=len;
        getNext();
        while(t)
        {
            ans[cnt++]=t;
            t=nex[t];
        }
        for(int i=cnt-1;i>=0;i--)
        {
            printf("%d",ans[i]);
            printf("%c",i?' ':'\n');
        }
    }
    return 0;
}
