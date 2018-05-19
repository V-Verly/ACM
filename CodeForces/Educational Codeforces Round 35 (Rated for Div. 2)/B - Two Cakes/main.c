#include<stdio.h>

int main(void){
    int n,a,b,i,t1,t2,t,x=0;
    scanf("%d%d%d",&n,&a,&b);
    for(i=1;i<n;i++){
        t1=a/i;
        t2=b/(n-i);
        //printf("%d %d\n",t1,t2);
        if(t1==0||t2==0) continue;
        if(t1<t2) t=t1;
        else t=t2;
        if(x<t) x=t;
    }
    printf("%d\n",x);
    return 0;
}
