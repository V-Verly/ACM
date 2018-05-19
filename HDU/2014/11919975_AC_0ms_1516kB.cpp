#include <stdio.h>
int main(void){
    int n,a[100],i,j,k,t;
    float s,ave;
    while(~scanf("%d",&n)){
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        if(a[k]<a[j]) k=j;
        if(k!=i)
        {t=a[k];
        a[k]=a[i];
        a[i]=t;}
    }
    for(i=1,s=0;i<n-1;i++){
        s=s+a[i];
    }
    ave=s/(n-2);
    printf("%.2f\n",ave);
    }
    return 0;
}