#include <stdio.h>
int main(void){
    int a,b;
    char c[2];
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%s%d%d",c,&a,&b);
    switch(c[0])
    {
        case '+':printf("%d\n",a+b);break;
        case '-':printf("%d\n",a-b);break;
        case '*':printf("%d\n",a*b);break;
        case '/':{
            
            if(a%b==0)printf("%d\n",a/b);
            else printf("%.2f\n",(double)a/b);
            break;
            }
    }
    }
    return 0;
}
