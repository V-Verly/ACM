#include <stdio.h>
#include<ctype.h>
#include<string.h>
int main(void){
    int i,j,flag,a,n;
    char ch[50];
    scanf("%d",&n);
    getchar();
        for(j=0;j<n;j++)
        {
            flag=1;
            gets(ch);
            if(!isalpha(ch[0])&& ch[0]!='_') flag=0;
            for(i=1;i<strlen(ch);i++)
            {
                if(!isalnum(ch[i])&&ch[i]!='_')
                flag=0;
            }
            if(flag)
            printf("yes\n");
            else
            printf("no\n");
        }
    return 0;
}