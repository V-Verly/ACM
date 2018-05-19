#include <stdio.h>
#include<string.h>
int main(void){
    char a[100005];
    int i,n,t,sum;
    scanf("%d",&t);
    getchar();    
    while(t--)
    {
        gets(a);
        n=strlen(a);
        sum=0;
        for(i=0;i<n;i++)
        if(a[i]<0) sum++;
        sum/=2;
        printf("%d\n",sum);
    }
    return 0;
}