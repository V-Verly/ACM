#include <stdio.h>
#include<string.h>
int vowel(char c);
int main ()
{
    int n,i,flag;
    char a[1000];
    while(scanf("%s",a)!=EOF)
    {
        if(strcmp(a,"end")==0) break;
        printf("<%s> ",a);
        flag=1;
        n=strlen(a);
        for(i=0;i<n;i++)
        if(vowel(a[i])) break;
        if(i==n) flag=0;
        for(i=0;i<n-2;i++)
    if(vowel(a[i])&&vowel(a[i+1])&&vowel(a[i+2])|| !vowel(a[i])&&!vowel(a[i+1])&&!vowel(a[i+2])) flag=0;
    for(i=0;i<n-1;i++)
    if(a[i]!='e'&&a[i]!='o'&&a[i]==a[i+1]) flag=0;
    if(flag) printf("is acceptable.\n");
    else printf("is not acceptable.\n");
    }
    return 0;
}
int vowel(char c)
{
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}
