#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct matrix{
long long a[2][2];
};
/*Matrix multiplication
c[i][j]=a[i][0]*b[0][j]+a[i][1]*b[1][j]
for(i=0;i<2;i++)
    for(j=0;j<2;j++)
        fib[1].a[i][j]=(fib[0].a[i][0]*fib[0].a[0][j]+fib[0].a[i][1]*fib[0].a[1][j])%10000;
*/
int main()
{
    matrix fib[3];
    long long n,i,j;
    while(scanf("%lld",&n)!=EOF&&n!=-1){
    fib[0].a[0][0]=1;
    fib[0].a[0][1]=1;
    fib[0].a[1][0]=1;
    fib[0].a[1][1]=0;
    fib[1].a[0][0]=1;
    fib[1].a[0][1]=0;
    fib[1].a[1][0]=0;
    fib[1].a[1][1]=1;
    if(n==0) printf("0\n");
    else{
    n--;
    while(n>0){
        if(n%2){
            for(i=0;i<2;i++)
                for(j=0;j<2;j++)
                    fib[2].a[i][j]=(fib[0].a[i][0]*fib[1].a[0][j]+fib[0].a[i][1]*fib[1].a[1][j])%10000;
        fib[1].a[0][0]=fib[2].a[0][0];
        fib[1].a[0][1]=fib[2].a[0][1];
        fib[1].a[1][0]=fib[2].a[1][0];
        fib[1].a[1][1]=fib[2].a[1][1];
        }
        for(i=0;i<2;i++)
            for(j=0;j<2;j++)
                fib[2].a[i][j]=(fib[0].a[i][0]*fib[0].a[0][j]+fib[0].a[i][1]*fib[0].a[1][j])%10000;
        fib[0].a[0][0]=fib[2].a[0][0];
        fib[0].a[0][1]=fib[2].a[0][1];
        fib[0].a[1][0]=fib[2].a[1][0];
        fib[0].a[1][1]=fib[2].a[1][1];
        n>>=1;
    }
    printf("%lld\n",fib[1].a[0][0]);
    }
    }
    return 0;
}
