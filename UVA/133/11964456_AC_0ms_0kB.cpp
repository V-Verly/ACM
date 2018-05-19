#include <stdio.h>
int n,k,m,a[30];
int go(int p,int q,int r);
int main()
{
    int left,p1,p2,i;
    while(scanf("%d%d%d",&n,&k,&m)!=EOF&&(n||m||k))
    {
        for(i=1;i<=n;i++)    a[i]=i;
        left=n,p1=n,p2=1;
        while(left)
        {
            p1=go(p1,1,k);
            p2=go(p2,-1,m);
            printf("%3d",p1);
            left--;
            if(p2!=p1){printf("%3d",p2);left--;}
            a[p1]=0;
            a[p2]=0;
            if(left) printf(",");
        }
        printf("\n");
    }
}
int go(int p,int q,int r)
{
    while(r--){
    do{p=(p+q+n-1)%n+1;}while(a[p]==0);
    }
    return p;
}