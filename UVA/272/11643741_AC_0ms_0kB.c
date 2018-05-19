#include <stdio.h>
int main()
{
    char a;
    int s=0;
    while((a=getchar())!=EOF)
    {
        if(a=='\"') 
        {
           if(s%2==0) printf("``"); 
           else printf("\'\'");
           s++;
       }
        else printf("%c",a);
    }
    return 0;
}