#include <stdio.h>
#include <string.h>
int main()
{
    char s[100005],t[100005];
    int m,n,i,j;
    while(scanf("%s%s",s,t)!=EOF)
    {
        m=strlen(s);
        n=strlen(t);
        j=0;
        for(i=0;i<n;i++)
        {
            if(j==m) break;
           if(s[j]==t[i]) j++;
       }
        if(j==m) printf("Yes\n");
        else printf("No\n");
        memset(s,0,sizeof(s));
        memset(t,0,sizeof(t));
    }
    return 0;
}
