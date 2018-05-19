#include<stdio.h>
int main()
{
    int n,i,j,s=0,a[10],b[10],c[10],flag,count=1;
    while(scanf("%d",&n)!=EOF&&n)
    {
        flag=0;
        for(i=0;i<n;i++)
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        for(i=0;i<1000000;i++)
        {
            s=0;
            for(j=0;j<n;j++)
            {
                if(c[j]<=a[j]) s++;
            }
           
            if(i>0){
                if(s>=n-s){
                for(j=0;j<n;j++)
                if(c[j]==a[j]) c[j]=0;
                }
            }
            for(j=0;j<n;j++)
            {
                if(c[j]==a[j]+b[j]) c[j]=0;
                c[j]++;
            }
            //printf("%d:%d\n",i+1,s);
            if(s==n) {flag=1;break;}
        }
        printf("Case %d: ",count++);
        if(flag) printf("%d\n",i+1);
        else printf("-1\n");
    }
}