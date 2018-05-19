#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n,i,ans,a[1005],I[1005];
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        ans=1;
        I[0]=a[0];
        for(i=1;i<n;i++)
        {
            int flag=1;
            for(int j=0;j<ans;j++)
                if(I[j]>=a[i]) {I[j]=a[i];flag=0;break;}
            if(flag)
                I[ans++]=a[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
