#include <stdio.h>
#include <string.h>
int main(void)
{
    int a,b,n,m,i,j,k,s[10005],t[10005];
    int flag;
    while(~scanf("%d%d",&a,&b))
    {
        printf("%d/%d = %d.",a,b,a/b);
        a=a%b;
        for(i=0;i<10000;i++)
        {
            a=a*10;
            t[i]=a;
            s[i]=a/b;
            a=a%b;
        }
        flag=1;
        for(i=1;i<10000;i++)
        {
            for(j=0;j<i;j++)
            if(t[j]==t[i]) {flag=0;break;}
            if(flag==0) break;
        }
        k=i-j;
        m=i,n=j;
        for(i=0;i<n;i++)
        printf("%d",s[i]);
        printf("(");
        if(m<=50){
        for(i=n;i<m;i++)
        printf("%d",s[i]);
        }
        else{ 
        for(i=n;i<50;i++)
        printf("%d",s[i]);
        printf("...");
        }
        printf(")\n");
        printf("   %d = number of digits in repeating cycle\n\n",k);
    }
    return 0;
}