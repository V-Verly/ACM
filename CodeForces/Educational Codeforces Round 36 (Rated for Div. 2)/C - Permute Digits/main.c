#include<stdio.h>
#include<string.h>
int main()
{
    char a[25],b[25],c[25],d[25],t;
    int i,j,k,m,n,r,flag,q;
    scanf("%s%s",a,b);
    n=strlen(a);
    m=strlen(b);
    for(i=0;i<n-1;i++)
        {
            k=i;
            for(j=i+1;j<n;j++)
            if(a[k]<a[j]) k=j;
            if(k!=i)
            {
                t=a[i];
                a[i]=a[k];
                a[k]=t;
            }
        }
        strcpy(d,a);
    if(m>n)
    {
       strcpy(c,a);
    }
    else
    {
        k=-1;
        r=-1;
        flag=0;
        q=25;
        for(i=0;i<n;i++)
        {
            flag=1;
            if(i<q){
            for(j=0;j<n;j++)
            {
                if(b[i]==a[j]&&a[j]!=' '&&j!=r)
                {
                    c[i]=a[j];
                    flag=0;
                    if(r!=-1) a[r]=' ';
                    r=j;
                    break;
                }
            }
            }
            if(flag)
            {
            for(j=0;j<n;j++)
            {
                if(b[i]>a[j]&&a[j]!=' '&&j!=r)
                {
                    c[i]=a[j];
                    a[j]=' ';
                    if(r!=-1) a[r]=' ';
                    flag=0;
                    break;
                }
            }
            }
            if(b[i]>c[i]&&c[i]>='0')
            {
                i++;
                //if(flag==0&&r!=-1) a[r]=' ';
                break;
            }
            if(flag)
            {
                q=i-1;
                i=-1;
                r=-1;
                strcpy(a,d);
            }
            }
        for(;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[j]!=' ')
                {
                    c[i]=a[j];
                    a[j]=' ';
                    break;
                }
            }
        }
        c[n]='\0';
    }
    printf("%s\n",c);
    return 0;
}
