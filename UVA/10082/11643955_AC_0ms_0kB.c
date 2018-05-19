#include <stdio.h>
#include <string.h>
int main()
{
    char a;
    char s[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    int i;
    while((a=getchar())!=EOF)
    {
       for(i=1;s[i]&&s[i]!=a;i++);
       if(s[i]) putchar(s[i-1]);
       else putchar(a);
       
    }
    return 0;
}