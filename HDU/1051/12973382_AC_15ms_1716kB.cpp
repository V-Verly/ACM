#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct com
{
    int l,w;
};
bool cmp(const com &a,const com &b)
{
    if(a.l==b.l)
        return a.w<b.w;
    return a.l<b.l;
}
int main()
{
    com a[5005];
    int n,i,ee;
    scanf("%d",&ee);
    while(ee--)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)
            scanf("%d%d",&a[i].l,&a[i].w);
        sort(a,a+n,cmp);
        int ans=0;
        int tmp[1005];
        tmp[0]=a[0].w;
        for(i=1; i<n; i++)
        {
            int r=-1,t=0;
            for(int j=0;j<=ans;j++){
                if(tmp[j]<=a[i].w&&tmp[j]>r){
                    r=tmp[j];
                    t=j;
                }
            }
            if(r==-1) tmp[++ans]=a[i].w;
            else tmp[t]=a[i].w;

        }
        printf("%d\n",ans+1);
    }
    return 0;
}
