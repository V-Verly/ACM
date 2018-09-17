#include<stdio.h>

int main()
{
    double n,mystack[205],sum;
    int mystack_size,i;
    char c;
    while(scanf("%lf",&n)!=EOF)
    {
        sum=0,mystack_size=0;
        c=getchar();
        if(n==0&&c=='\n') break;
        mystack[mystack_size++]=n;
        c=getchar();
        while(1)
        {
            scanf("%lf",&n);
            if(c=='+') mystack[mystack_size++]=n;
            else if(c=='-') mystack[mystack_size++]=-n;
            else if(c=='*') mystack[mystack_size-1]*=n;
            else if(c=='/') mystack[mystack_size-1]/=n;
            c=getchar();
            if(c=='\n') break;
            c=getchar();
        }
        for(i=0;i<mystack_size;i++)
        sum+=mystack[i];
        printf("%.2f\n",sum);
    }
    return 0;
}