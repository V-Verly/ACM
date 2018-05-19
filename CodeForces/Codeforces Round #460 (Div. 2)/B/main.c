#include <stdio.h>
#include <stdlib.h>
int judge(int x){
int s=0;
while(x){
    s+=x%10;
    x/=10;
}
return s;
}
int main()
{
    int a[10005],k,i,s,n;
    s=19;
    k=1;
    while(k<=10000){
        if(judge(s)==10) a[k++]=s;
        s+=9;
    }
    scanf("%d",&n);
    printf("%d\n",a[n]);
    return 0;
}

