#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


char s[200005];
int a[200000],b[200000]= {0},c[200000]={0};
int main()
{
    int n,i,j,flag,t;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);

    }
    scanf("%s",s);
    flag=1;
    t=0;
    for(i=0; i<n; i++)
    {
        if(a[i]>i+1)
        {
            if(t==0||i>c[t-1]||a[i]-2<b[t-1])
            {
              b[t]=i;
              c[t++]=a[i]-2;
            }

            else if(i<b[t-1]&&a[i]-2<c[t-1]) b[t-1]=i;
            else if(i>b[t-1]&&a[i]-2>c[t-1]) c[t-1]=a[i]-2;

        }
    }
    flag=1;
    for(i=0;i<t;i++){
        //printf("%d %d\n",b[i],c[i]);
        for(j=b[i];j<=c[i];j++)
        if(s[j]=='0'){flag=0;break;}
    }
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
