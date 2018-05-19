#include <stdio.h>
int main(void){
    int n,a[100],i,j,k,t;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        t=0;
        for(i=0;i<n;i++)
        if(a[t]>a[i]) t=i;
        if(t!=0)
        {
            k=a[t];
            a[t]=a[0];
            a[0]=k;
        }
        for(i=0;i<n;i++)
        {
            if(i) printf(" ");
            printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}