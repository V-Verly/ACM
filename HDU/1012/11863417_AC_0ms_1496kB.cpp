#include <stdio.h>
#include <string.h>
int main(void){
    double t,n,e;
    int i;
    n=0,e=1,t=1;
    printf("n e\n- -----------\n");
    printf("0 1\n1 2\n2 2.5\n");
        for(i=1;i<=9;i++)
        {
            t*=i;
            e+=1/t;
            if(i>=3)printf("%d %.9f\n",i,e);
        }
    return 0;
}
