#include <stdio.h>
#include <string.h>
int main(void){
    int n,i,t,s;
    char a[10000];
    scanf("%d",&t);
    while(t--)
    {
        s=0;
        scanf("%s",a);
        n=strlen(a);
        for(i=0;i<n;i++)
        if(a[i]>='0'&&a[i]<='9') s++;
        printf("%d\n",s);
    }
    return 0;
}