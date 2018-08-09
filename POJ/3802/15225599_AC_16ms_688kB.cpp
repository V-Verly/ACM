#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int w,d,a[15],b[15],va[15],vb[15],ans;
    while(scanf("%d%d",&w,&d)!=EOF&&(w||d))
    {
        memset(va,0,sizeof(va));
        memset(vb,0,sizeof(vb));
        for(int i=0;i<w;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<d;i++)
            scanf("%d",&b[i]);
        sort(a,a+w);
        sort(b,b+d);
        int ans=0;
        for(int i=0;i<w;i++)
        {
            bool flag=false;
            for(int j=0;j<d;j++)
            {
                if(!vb[j]&&a[i]==b[j])
                {
                    va[i]=true;
                    vb[j]=true;
                    ans+=b[j];
                    flag=true;
                }
                if(flag) break;
            }
        }

        for(int i=0;i<w;i++)
            if(!va[i]) ans+=a[i];
        for(int i=0;i<d;i++)
            if(!vb[i]) ans+=b[i];
        printf("%d\n",ans);
    }
    return 0;
}
