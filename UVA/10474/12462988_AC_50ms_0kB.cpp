#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;


int main()
{
    int m,n,i,x,a[10005],kase=1;
    while(scanf("%d%d",&m,&n)!=EOF&&(m||n))
    {
        printf("CASE# %d:\n",kase++);
        for(i=0;i<m;i++)
            scanf("%d",&a[i]);
        sort(a,a+m);
        while(n--){
            scanf("%d",&x);
            int p=lower_bound(a,a+m,x)-a;
            if(a[p]==x) printf("%d found at %d\n",x,p+1);
            else printf("%d not found\n",x);
        }
    }
    return 0;
}
