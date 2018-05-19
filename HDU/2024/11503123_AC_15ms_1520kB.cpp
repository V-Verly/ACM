#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int n,l,i,flag;
    char a[100];
    scanf("%d",&n);
    getchar();
while(n--)
{
    flag=1;
        gets(a);
        l=strlen(a);
            if((isalpha(a[0])||a[0]=='_')==0)
             flag=0;
        for(i=1;i<l;i++)
            {
                if((isalnum(a[i])||a[i]=='_')==0)
                 flag=0;
            }
        if(flag) printf("yes\n");
        else printf("no\n");

    }
    return 0;
}
