#include <stdio.h>
#include <string.h>
int main()
{
    int n,i,count1,count2,sum,b[26];
    char s[100],a[100];
    while(scanf("%d",&n)!=EOF&&n!=-1)
    {
        count1=0,count2=0,sum=0;
        memset(b,0,sizeof(b));
        scanf("%s%s",s,a);
        for(i=0;i<strlen(s);i++)
        b[s[i]-'a']=1;
        for(i=0;i<26;i++)
        if(b[i]) sum++;
        for(i=0;i<strlen(a);i++)
        {
            if(b[a[i]-'a']==1) 
            {
                b[a[i]-'a']=0;
                count1++;
            }
            else count2++;
            if(count2==7||count1==sum) break;
        }
        printf("Round %d\n",n);
        if(count2==7) printf("You lose.\n");
        else if(count2<7)
        {
            if(count1==sum) printf("You win.\n");
            else printf("You chickened out.\n");
        }
    }
}
