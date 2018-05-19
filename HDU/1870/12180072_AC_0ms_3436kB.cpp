#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000000],s[1000000];
    int len,n,i;
    while(gets(a)!=NULL)
    {
        n=strlen(a);
        len=0;
        for(i=0;i<n;i++)
        {            
            if(a[i]=='B') break;
            if(len==0){
                if(a[i]=='(') s[len++]='(';
            }
            else
            {
                if(a[i]=='(') s[len++]='(';
                else if(a[i]==')'&&s[len-1]=='(') len--;
            }
        }
        printf("%d\n",len);
    }
    return 0;
}