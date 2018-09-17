#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void exgcd(int a,int b,int &x,int &y)
{
    if(!b) x=1,y=0;
    else exgcd(b,a%b,y,x),y-=a/b*x;
}

int inv(int a,int b)
{
    int x,y;
    exgcd(a,b,x,y);
    x=(x%b+b)%b;
    if(!x) x+=b;
    return x;
}

int main()
{
    int t,n,m,a[15],b[15];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++) scanf("%d",&a[i]);
        for(int i=0;i<m;i++) scanf("%d",&b[i]);
        int a1,a2,b1,b2;
        bool flag=true;
        for(int i=1;i<m;i++)
        {
            a1=a[i-1],a2=a[i],b1=b[i-1],b2=b[i];
            int t=__gcd(a1,a2);
            if((b2-b1)%t) {flag=false;break;}
            a[i]=a1*a2/t;
            b[i]=inv(a1/t,a2/t)*((b2-b1)/t)%(a2/t)*a1+b1;
            b[i]=(b[i]%a[i]+a[i])%a[i];
        }
        if(!flag) printf("0\n");
        else
        {
            if(n<b[m-1]) {printf("0\n");continue; }
            int ans=(n-b[m-1])/a[m-1]+1;
            if(!b[m-1]) ans--;
            printf("%d\n",ans);
        }
    }
    return 0;
}
