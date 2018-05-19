#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,t,k,i,a[200],x[200],y[200],time;
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        scanf("%d%d",&n,&k);
        for(i=0; i<k; i++)
        {
            scanf("%d",&x[i]);
            y[i]=x[i];
        }
        time=0;
        for(;;)
        {
            time++;
            for(i=0;i<k;i++){
                if(x[i]>0) {
                    a[x[i]-1]=1;
                    x[i]--;
                }
                if(y[i]<=n){
                    a[y[i]-1]=1;
                    y[i]++;
                }
            }
            int flag=1;
            for(i=0;i<n;i++){
                if(a[i]==0) {flag=0;break;}
            }
            if(flag) break;
        }
        printf("%d\n",time);
    }
    return 0;
}
