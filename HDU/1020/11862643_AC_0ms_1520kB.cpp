#include <stdio.h>
#include <string.h>
int main(void){
    int n,t,i,s;
    char a[10005];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",a);
        i=0;
        while(a[i]!='\0')
        {
            n=i;
            while(a[n+1]==a[i]&&a[n+1]!='\0')
                n++;
            if(n>i) printf("%d",n-i+1);
            printf("%c",a[i]);
            i=n;
            i++;
        }
        printf("\n");
    }
    return 0;
}
