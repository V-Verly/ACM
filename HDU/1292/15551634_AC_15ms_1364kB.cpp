#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    long long b[30],t[30];
    b[0]=b[1]=t[0]=1;
    for(int i=2;i<25;i++)
    {
        t[i-1]=b[i-1];
        for(int j=i-2;j>=0;j--)
            t[j]=(t[j]+t[j+1]);
        b[i]=t[0];
    }
    int s,n;
    scanf("%d",&s);
    while(s--)
    {
        scanf("%d",&n);
        printf("%lld\n",b[n]);
    }
    return 0;
}
