#include <stdio.h>
int main(void)
{
    int t;
    while(~scanf("%d",&t))
    {
        if(t>100||t<0) printf("Score is error!\n");
        else if(t>=90) printf("A\n");
        else if(t>=80) printf("B\n");
        else if(t>=70) printf("C\n");
        else if(t>=60) printf("D\n");
        else printf("E\n");
       }
    return 0;
}