#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int m,n,i;
    double a[5005],b[5005],c[5005],s;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%lf%lf",&a[i],&b[i]);
        c[i]=a[i]/b[i];
    }
    sort(c,c+n);
    s=m*c[0];
    printf("%.8f\n",s);
    return 0;
}

