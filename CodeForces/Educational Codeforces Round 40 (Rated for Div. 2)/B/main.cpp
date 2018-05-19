#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n,i,j,t,r=0;
    char a[105];
    scanf("%d",&n);
    scanf("%s",a);
    t=n;
    for(i=n/2;i>0;i--)
    {
        if(a[i]==a[0])
        {
            int flag=1;
            for(j=0;j<i;j++)
                if(a[i+j]!=a[j]) {flag=0;break;}
            if(flag)
            {
                r=i;
                break;
            }
        }
    }
    if(r) t=n-r+1;
    else t=n;
    printf("%d\n",t);
    return 0;
}
