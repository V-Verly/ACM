#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[1005],b[1005],c[1005];
    int m,n,i,j,k,s,t;
    scanf("%d",&t);
    for(int _=1;_<=t;_++)
    {
        if(_>1) printf("\n");
        printf("Case %d:\n",_);
        scanf("%s%s",a,b);
        printf("%s + %s = ",a,b);
        m=strlen(a);
        n=strlen(b);
        i=0;
        s=0;
        j=m-1;
        k=n-1;
        while(i<m||i<n||s!=0){
            if(j>=0) s+=a[j--]-'0';
            if(k>=0) s+=b[k--]-'0';
            c[i++]=s%10+'0';
            s/=10;
        }
        c[i]=0;
        for(i--;i>=0;i--)
            printf("%c",c[i]);
        printf("\n");
        memset(c,0,sizeof(c));
    }
    return 0;
}
