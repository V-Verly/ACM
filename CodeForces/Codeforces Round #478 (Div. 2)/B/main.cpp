#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    long long a[15],b[15];
    for(int i=1;i<15;i++)
    {
        scanf("%lld",&a[i]);
        b[i]=a[i];
    }
    long long mx=0,ans;
    for(int i=1;i<15;i++)
    {
        ans=0;
        if(a[i])
        {
            b[i]=0;
            for(int j=1;j<15;j++)
            {
                b[j]+=a[i]/14;
                if((j-i+14)%14<=a[i]%14&&j!=i) b[j]++;
            }
            for(int j=1;j<15;j++)
            {
                if(b[j]%2==0) ans+=b[j];
            }
        }
        mx=max(ans,mx);

        for(int j=1;j<15;j++)
            b[j]=a[j];
    }
    printf("%lld\n",mx);
    return 0;
}
