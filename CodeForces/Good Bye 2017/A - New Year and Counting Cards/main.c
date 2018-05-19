#include<stdio.h>
#include<string.h>
int main()
{
    char s[55];
    int i,n=0;
    scanf("%s",s);
    for(i=0;i<strlen(s);i++)
    if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='1'||s[i]=='3'||s[i]=='5'||s[i]=='7'||s[i]=='9') n++;
    printf("%d\n",n);
    return 0;
}
