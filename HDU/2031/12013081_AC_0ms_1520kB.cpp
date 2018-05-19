#include <stdio.h>
#include <math.h>
#include <string.h>
int main(void)
{
    int b,n,r,i,a[100];
    while(~scanf("%d %d",&n,&r))
    {
        memset(a,0,100*sizeof(int));
        i=0;
        if(n<0)
        printf("-");
        do
        {
            a[i]=abs(n%r);
            n=n/r;
            i++;
        }while(n!=0);
        b=i-1;
        if(2<=r&&r<=9){
        for(i=b;i>=0;i--){
            printf("%d",a[i]);
            }
            printf("\n");
        }
        else
        {
            for(i=b;i>=0;i--){
                if(a[i]==10)
                printf("A");
                else if(a[i]==11)
                printf("B");
                else if(a[i]==12)
                printf("C");
                else if(a[i]==13)
                printf("D");
                else if(a[i]==14)
                printf("E");
                else if(a[i]==15)
                printf("F");
                else
                printf("%d",a[i]);
            }
            printf("\n");
        }
    }
}