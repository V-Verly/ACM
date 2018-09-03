#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int t,n,m,k;
    double p;
    scanf("%d",&t);
    for(int _=1;_<=t;_++)
    {
        scanf("%d%d%d%lf",&n,&m,&k,&p);
        double res=n*p*k;
        printf("Case %d: %.6f\n",_,res);
    }
    return 0;
}
