#include <cmath>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int p,y,i,j,flag=0;
    scanf("%d%d",&p,&y);
    for(i=y;i>p;i--)
    {
        flag=1;
        for(j=2;j*j<=i&&j<=p;j++)
        {
            if(i%j==0) {flag=0;break;}
        }
        if(flag) break;
    }
    if(flag)
    printf("%d\n",i);
    else printf("-1\n");
    return 0;
}
