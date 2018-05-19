#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int l,r,a,s=0,t;
    scanf("%d%d%d",&l,&r,&a);
    t=min(l,r);
    s+=2*t;
    l-=t;
    r-=t;
    if(l)
    {
        t=min(l,a);
        s+=2*t;
        l-=t;
        a-=t;
    }
    else{
        t=min(r,a);
        s+=2*t;
        r-=t;
        a-=t;
    }
    if(a)
    {
        if(a%2) a--;
        s+=a;
    }
    printf("%d\n",s);
    return 0;
}
