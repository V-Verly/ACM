#include <stdio.h>
int fun(int a,int b,long long n);
int main(void){
    int a,b,i,r,t[1000];
    long long n,j;
    while(scanf("%d%d%lld",&a,&b,&n)!=EOF&&(a!=0||b!=0||n!=0))
    {
    r=0;
    t[1]=1,t[2]=1;
    for(i=3;i<1000;i++)
    {
        t[i]=(b*t[i-2]+a*t[i-1])%7;
        for(j=2;j<i-2;j++)
        if(t[i]==t[j]&&t[i-1]==t[j-1]&&j!=i) {r=i-j;break;}
        if(r) break;
    }
    
    printf("%d\n",t[(n-j)%r+j]);
    }
    return 0;
}
