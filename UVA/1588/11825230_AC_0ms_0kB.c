#include <stdio.h>
#include <string.h>
int main(void)
{
    int m,n,i,j,t,s1,s2;
    char a[205],b[205];
    while(scanf("%s%s",a,b)!=EOF)
    {
        i=0,j=0,t=0;
        m=strlen(a);
        n=strlen(b);
        while(i<m&&j<n)
        {
            if(a[i]=='2'&&b[j]=='2') {i=0;t++;j=t;}
            else {i++;j++;}
        }
        s1=m+n-i;
        i=0,j=0,t=0;
        while(i<m&&j<n)
        {
            if(a[i]=='2'&&b[j]=='2') {j=0;t++;i=t;}
            else {i++;j++;}
        }
        s2=m+n-j;
        if(s1>s2) printf("%d\n",s2);
        else printf("%d\n",s1);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
    }
    return 0;
}