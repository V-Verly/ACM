#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    char a[1005];
    int s,n,i;
    while(scanf("%s%d",a,&s)!=EOF){
        n=strlen(a);
        if(s==n) printf("0\n");
        else{
        while(s){
            for(i=0;i<n;i++)
                if(a[i]>a[i+1]) break;
            for(int j=i;j<n;j++)
                a[j]=a[j+1];
            s--;
        }
        n=strlen(a);
        while(a[0]=='0'&&n>1)
        {
            i=0;
            while(i<n)
            {
                a[i]=a[i+1];
                i++;
            }
            n=strlen(a);

        }
        printf("%s\n",a);
        }
    }
    return 0;
}
