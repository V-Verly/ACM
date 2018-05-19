#include<stdio.h>
int main(void)
{
    int i,j,k,m,n,s,t,c;
    scanf("%d",&c);
    while(c--){
    s=0;
    scanf("%d%d",&m,&n);
    for(i=0;i<=(m+n)/2;i++)
        for(j=0;j<=(m+n)/3;j++)
            for(k=0;k<=(m+n)/6;k++)
            {
                t=i+2*j+5*k;
                if(t==n&&i+j+k==m) s++;
            }
        printf("%d\n",s);
    }
    return 0;
}