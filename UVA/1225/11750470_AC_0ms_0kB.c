#include <stdio.h>
int main(void)
{
    long long int t,i,n,s,f;
    int t0,t1,t2,t3,t4,t5,t6,t7,t8,t9;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        t0=0,t1=0,t2=0,t3=0,t4=0,t5=0,t6=0,t7=0,t8=0,t9=0;
        for(i=1;i<=n;i++)
        {
            s=i;
            while(s>0)
            {
                f=s%10;
                s=s/10;
                switch(f)
                {
                    case 0:t0++;break;
                    case 1:t1++;break;
                    case 2:t2++;break;
                    case 3:t3++;break;
                    case 4:t4++;break;
                    case 5:t5++;break;
                    case 6:t6++;break;
                    case 7:t7++;break;
                    case 8:t8++;break;
                    case 9:t9++;break;
                }
            }
        }
        printf("%d %d %d %d %d %d %d %d %d %d\n",t0,t1,t2,t3,t4,t5,t6,t7,t8,t9);
    }
    
    return 0;
}