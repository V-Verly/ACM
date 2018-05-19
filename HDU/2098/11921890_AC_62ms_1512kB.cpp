#include<stdio.h>
#include<math.h>
int prime(int n);
int main(void)
{
    int n,i,s;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        s=0;
        for(i=3;i<n/2;i++)
        if(prime(i)&&prime(n-i)) s++;
        printf("%d\n",s);
    }
}
int prime(int n)
{
    int i;
    for(i=2;i<=sqrt(n);i++)
    if(n%i==0) return 0;
    return 1;
}