#include <stdio.h>
int main(void){
    int n,m,i,sum,r;
    double t,a[50];
    r=1;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        sum=0,m=0;
        for(i=0;i<n;i++)
        {
        scanf("%lf",&a[i]);
        sum=sum+a[i];
        }
        t=sum/n;
        for(i=0;i<n;i++)
        {
            if(a[i]>t)
            m+=a[i]-t;
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",r++,m);
    }
    return 0;
}
