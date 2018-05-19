#include <stdio.h>
#include<string.h>
int main(void){
    char ch[100];
    int i,j;
    while(gets(ch)!=NULL)
    {
        ch[0]=(int)ch[0]-32;
        for(i=1;i<strlen(ch)-1;i++)
        {
            if(ch[i]==' ')
            ch[i+1]=(int)ch[i+1]-32;
        }
        puts(ch);
    }
    return 0;
}
