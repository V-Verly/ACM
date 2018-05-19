#include <stdio.h>
#include <stdlib.h>
char s[200005];
int a[200000],b[200000]= {0},c[200000]={0};
int main()
{
    int n,i,j,flag,t;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);

    }
    scanf("%s",s);
    flag=1;
    for(i=0; i<n; i++)
    {
        if(a[i]>i+1)
        {
            b[i]=1;
            c[a[i]-2]=1;
        }
    }
    for(i=0; i<n-1; i++)
    {
        if(b[i]&&s[i]=='0')
        {
            flag=0;
            break;
        }
    }
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
