#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=32000+10;

int n,c[maxn],a[maxn];
inline int lowbit(int x) {return x&(-x); }

int sum(int x)
{
    int ret=0;
    while(x>0) {
        ret+=c[x]; x-=lowbit(x);
    }
    return ret;
}

void add(int x,int d)
{
    while(x<=32001) {
        c[x]+=d; x+=lowbit(x);
    }
}

int main()
{
    int x,y;
    scanf("%d",&n);
    memset(c,0,sizeof c);
    memset(a,0,sizeof a);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        a[sum(x+1)]++;
        add(x+1,1);
    }
    for(int i=0;i<n;i++) printf("%d\n",a[i]);
    return 0;
}
