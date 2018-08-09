#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int m,_=0;
    while(scanf("%d",&m)!=EOF)
    {
        double k=log10(2);
        int ans=k*m;
        printf("Case #%d: %d\n",++_,ans);
    }
    return 0;
}
