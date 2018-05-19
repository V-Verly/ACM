#include <stdio.h>
int main(void)
{
    int t,i,n,k,s;
    char a[85];
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        k=1,s=0;
        memset(a,0,sizeof(a));
        gets(a);
        n=strlen(a);
        for(i=0;i<n;i++)
        {
            if(a[i]=='O')
            {
                s=s+k;
                k++;
            }
            else k=1;
        }
        printf("%d\n",s);
    }
    return 0;
}