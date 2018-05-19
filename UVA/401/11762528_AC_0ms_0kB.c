#include <stdio.h>
#include <ctype.h>
#include <string.h>
const char* rev="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* msg[]={"not a palindrome.", "a regular palindrome.","a mirrored string.","a mirrored palindrome."};
char r(char ch)
{
    if(isalpha(ch)) return rev[ch-'A'];
    return rev[ch-'0'+25];
}

int main(void)
{
   char s[30];
   int n,i,p,q;
   while(scanf("%s",s)==1)
    {
        p=1,q=1;
        n=strlen(s);
        for(i=0;i<n/2+1;i++)
        {
            if(s[i]!=s[n-i-1]) p=0;
            if(s[i]!=r(s[n-i-1])) q=0;
        }
        printf("%s -- is %s\n\n",s,msg[p+q*2]);
    }
    return 0;
}