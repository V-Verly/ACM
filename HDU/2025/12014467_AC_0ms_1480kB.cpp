#include <stdio.h>
#include<ctype.h>
#include<string.h>
int main(void){
    char a[105],max;
    int i,n;
    while(gets(a)!=NULL)
    {
        max='A';
        n=strlen(a);
        for(i=0;i<n;i++)
        if(a[i]>max) max=a[i];
        for(i=0;i<n;i++)
        {
            printf("%c",a[i]);
            if(a[i]==max) printf("(max)");
        }
        printf("\n");
    }
    return 0;
}