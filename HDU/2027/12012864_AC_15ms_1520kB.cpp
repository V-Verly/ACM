#include <stdio.h>
#include<string.h>
int main(void)
{
    char ch[100];
    int i,j,a,e,t,o,u,n;
    scanf("%d%*c",&n);
    for(j=0;j<n;j++)
    {
    if(j) printf("\n");
    memset(ch,0,sizeof(ch));
    gets (ch);
    a=0,e=0,t=0,o=0,u=0; 
    for(i=0;i<strlen(ch);i++)
    {
        switch(ch[i])
        {
            case 'a':a++;break;
            case 'e':e++;break;
            case 'i':t++;break;
            case 'o':o++;break;
            case 'u':u++;break;
            default:break;
        }
    }
    printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",a,e,t,o,u);
    }
    return 0;
    
}