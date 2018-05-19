#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int l,n,m,i,j,k,a[505],b[505],c[505],r[505*505],s,x,ans=0;
    while(scanf("%d%d%d",&l,&n,&m)!=EOF)
    {
        for(i=0;i<l;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
            scanf("%d",&b[i]);
        for(i=0;i<m;i++)
            scanf("%d",&c[i]);
        printf("Case %d:\n",++ans);
        scanf("%d",&s);
        int e=0;
        for(i=0;i<l;i++)
            for(j=0;j<n;j++)
            r[e++]=a[i]+b[j];
        sort(r,r+e);
        while(s--)
        {
            scanf("%d",&x);
            int flag=0;
            for(i=0;i<m;i++)
            {
                int q=x-c[i];
                int left=0,right=e;
                while(left<=right)
                {
                    int mid=(left+right)/2;
                    if(r[mid]>q) right=mid-1;
                    else if(r[mid]<q) left=mid+1;
                    else {flag=1;break;}
                }
                if(flag) break;
            }
            if(flag) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
