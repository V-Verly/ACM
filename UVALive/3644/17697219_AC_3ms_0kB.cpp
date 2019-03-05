#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e5+10;

int pre[maxn];

int Find(int x) {return x==pre[x]?x:pre[x]=Find(pre[x]); }

int main()
{
    int u,v;
    while(scanf("%d",&u)!=EOF)
    {
        for(int i=0;i<maxn;i++) pre[i]=i;
        int cnt=0;
        while(u!=-1)
        {
            scanf("%d",&v);
            int fx=Find(u),fy=Find(v);
            if(fx==fy) cnt++;
            else pre[fx]=fy;
            scanf("%d",&u);
        }
        printf("%d\n",cnt);
    }
    return 0;
}
