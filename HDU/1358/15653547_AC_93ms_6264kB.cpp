#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e6+10;
char a[maxn];
int nex[maxn],n;

void getNext()
{
    int i=0,j=-1,st=0;
    nex[0]=-1;
    while(i<n)
    {
        if(j==-1||a[i]==a[j])
            nex[++i]=++j;
        else
            j=nex[j];
    }
}

int main()
{
    int cnt=0;
    while(scanf("%d",&n)!=EOF&&n)
    {
        printf("Test case #%d\n",++cnt);
        scanf("%s",a);
        getNext();
        for(int i=1;i<=n;i++)
        {
            if(i%(i-nex[i])==0&&nex[i])
                printf("%d %d\n",i,i/(i-nex[i]));
        }
        printf("\n");
    }
    return 0;
}
