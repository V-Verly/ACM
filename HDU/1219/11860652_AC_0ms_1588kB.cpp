#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void){
    int i,n,s[26];
    char a[100005];
    while(gets(a)!=NULL)
    {
        n=strlen(a);
        memset(s,0,sizeof(s));
        for(i=0;i<n;i++)
        {
           if(a[i]>='a'&&a[i]<='z') s[a[i]-'a']++;
        }
        for(i=0;i<26;i++)
        printf("%c:%d\n",i+'a',s[i]);
        printf("\n");
        memset(a,0,sizeof(a));
    }
    return 0;
}
