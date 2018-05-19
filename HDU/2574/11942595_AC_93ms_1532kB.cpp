#include<stdio.h>
#include<math.h>
#include<string.h>
long long prime(long long n);
int main(void){
    int t,n,i,max;
    long long b[1005];
    char a[1005][25];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%s%lld",a[i],&b[i]);
        for(i=0;i<n;i++)
        b[i]=prime(b[i]);
        max=0;
        for(i=0;i<n;i++){
        if(b[i]>b[max]) max=i;
        else if(b[max]==b[i]&&strcmp(a[max],a[i])>0)
        max=i;
        }
        printf("%s\n",a[max]);
    }
}
long long prime(long long n){
    int i=2,count=0;
    while(n!=1&&i*i<n)
    {
        if(n%i==0)
        {
            count++;
            while(n%i==0) n/=i;
        }
        else i++;
    }
    if(n!=1) count++;
    return count;
}