#include <stdio.h>
#include <string.h>
int main()
{
    int n,a,e,i,o,u,j,l;
    char ch[100];
    scanf("%d",&n);
    getchar();
   while(n--)
   {
       gets(ch);
       l=strlen(ch);
       a=0,e=0,i=0,o=0,u=0;
       for(j=0;j<l;j++)
       {
           switch(ch[j])
           {
           case'a':a++;break;
           case'e':e++;break;
           case'i':i++;break;
           case'o':o++;break;
           case'u':u++;break;
           default:break;
           }
       }
       printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",a,e,i,o,u);
       if(n!=0) printf("\n");
       memset(ch,0,100*sizeof(char));
   }
    return 0;
}
