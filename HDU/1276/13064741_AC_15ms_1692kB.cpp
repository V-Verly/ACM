#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n,i,t,k,s[5005];
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            memset(s,0,sizeof(s));
            scanf("%d",&n);
            for(i=0; i<n; i++)
                s[i]=1;
            k=n;
            int r=1;
            while(k>3)
            {
                int j=0;
                k=0;
                if(r%2==0)
                {
                    for(i=0; i<n; i++)
                        if(s[i])
                        {
                            j++;
                            if(j%3==0) s[i]=0;
                            else k++;
                        }
                }
                else{
                    for(i=0;i<n;i++)
                        if(s[i])
                        {
                            j++;
                            if(j%2==0) s[i]=0;
                            else k++;
                        }
                }
                r++;
            }
            int cou=0;
            for(i=0;i<n;i++)
            {

                if(s[i])
                {
                    if(cou++) printf(" ");
                    printf("%d",i+1);
                }
            }
            printf("\n");
        }

    }
    return 0;
}
