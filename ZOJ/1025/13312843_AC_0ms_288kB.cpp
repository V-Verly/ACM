#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct stick{
int l,w;
};

bool cmp(const stick &a,const stick &b)
{
    if(a.l==b.l) return a.w<b.w;
    return a.l<b.l;
}

int main()
{
    int t,n,i;
    stick s[5005];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d%d",&s[i].l,&s[i].w);
        sort(s,s+n,cmp);
        int ans=0;
        int tmp[5005];
        tmp[0]=s[0].w;
        for(i=1;i<n;i++)
        {
            int r=-1,t=0;
            for(int j=0;j<=ans;j++)
            {
                if(tmp[j]<=s[i].w&&tmp[j]>r)
                {
                    r=tmp[j];
                    t=j;
                }
            }
            if(r==-1) tmp[++ans]=s[i].w;
            else tmp[t]=s[i].w;
        }
        printf("%d\n",ans+1);
    }
    return 0;
}
