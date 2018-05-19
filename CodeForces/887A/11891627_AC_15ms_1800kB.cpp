#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[105];
    int t,n,i;
    while(~scanf("%s",s))
    {
        n=strlen(s);
        t=n;
        for(i=1;i<n;i++)
            if(s[i]=='1') t--;
        if(t>6) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
