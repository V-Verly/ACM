#include <stdio.h>
#include <string.h>
int main(void){
    char a[1000];
    int n,i,t,s;
    while(scanf("%s",a)!=EOF)
    {
        if(a[0]=='0') break;
        s=0;
        n=strlen(a);
        for(i=0;i<n;i++)
        s+=a[i]-'0';
        while(s>=10)
        {
            t=0;
            while(s>0)
            {
                t+=s%10;
                s/=10;
            }
            s=t;
        }
        printf("%d\n",s);
    }
    return 0;
}
