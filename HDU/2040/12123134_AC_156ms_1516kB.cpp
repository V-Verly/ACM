#include <stdio.h>
#include <stdlib.h>
int relate(int n);
int main()
{
    int a,b,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        if(relate(a)==b&&relate(b)==a) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
int relate(int n){
int i=1,s=0;
for(i=1;i<n;i++)
    if(n%i==0) s+=i;
return s;
}
