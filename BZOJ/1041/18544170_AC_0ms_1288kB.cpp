#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    long long ans=1;
    scanf("%d",&n);
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            int cnt=0;
            while(n%i==0)
            {
                n/=i;
                cnt++;
            }
            cnt*=2;
            if(i==2) continue;
            if(i%4==1) ans*=cnt+1;
            else if(i%4==3&&cnt%2==1) {
                ans=0;
                break;
            }
        }
    }
    if(n>1)
    {
        if(n%4==1) ans*=3;
       // else if(n%4==3) ans=0;
    }
    printf("%lld\n",4*ans);
    return 0;
}
