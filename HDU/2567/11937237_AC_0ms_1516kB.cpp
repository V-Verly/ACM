#include<stdio.h>
#include<string.h>
int main(void)
{
    int t,m,n,i;
    char a[110],b[55];
   scanf("%d",&t);
   getchar();
   while(t--)
   {
       gets(a);
       gets(b);
       m=strlen(a);
       n=strlen(b);
       for(i=m-1;i>=m/2;i--)
       a[i+n]=a[i];
       for(i=0;i<n;i++)
       a[m/2+i]=b[i];
       for(i=0;i<m+n;i++)
       printf("%c",a[i]);
       printf("\n");
   }
    return 0;
}