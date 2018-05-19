#include<iostream> 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(void){
    int m,n,i,t,count=1;
    double sum,v,h,s,a[900];
    while(scanf("%d%d",&m,&n)!=EOF&&(m||n)){
        sum=0;
        for(i=0;i<m*n;i++)
        scanf("%lf",&a[i]);
        scanf("%lf",&v);
        sort(a,a+m*n);
        for(i=1;i<m*n;i++)
        {
            sum+=(a[i]-a[i-1])*i*100;
            if(sum>=v) {sum-= (a[i]-a[i-1])*i*100; break;}
        }
        t=i;
        v-=sum;
        h=v/(t*100)+a[t-1];
        if(v==0) s=(double)(t-1)*100/(m*n);
        else s=(double)t*100/(m*n);
        printf("Region %d\nWater level is %.2f meters.\n%.2f percent of the region is under water.\n\n",count++,h,s);
    }
}