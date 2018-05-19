#include<stdio.h>
#include<string.h>
void hex(char data[],char text[]){
    int s=0;
    s+=(data[0]-'0')*8+(data[1]-'0')*4+(data[2]-'0')*2+data[3]-'0';
    if(0<=s&&s<=9) text[0]=s+'0';
    else text[0]=s-10+'A';
}
int main()
{
    int d,s,b,i,j,t,a,sum,flag,sign,count=1;
    char c[5],disk[7][10005], data[50000],text[20000];
    while(scanf("%d",&d)!=EOF&&d)
    {
        flag=1;
        memset(data,'0',sizeof(data));
        memset(text,0,sizeof(text));
        scanf("%d%d",&s,&b);
        scanf("%s",c);
        if(c[0]=='E') sign=0;
        else sign=1;
        for(i=0;i<d;i++)
        scanf("%s",disk[i]);
        for(i=0;i<s*b;i++)
        {
            a=0;
            sum=0;
            for(j=0;j<d;j++)
            {
                if(disk[j][i]=='0') a^=0;
                else if(disk[j][i]=='1') a^=1;
                else if(disk[j][i]=='x') {
                    sum++;
                    t=j;
                }
            }
            if(sum>1||sum==0&&a!=sign) {flag=0;break;}
            if(sum==1)
                disk[t][i]=a^sign+'0';
        }
        if(flag)
        {
            t=0;
            for(i=0;i<b;i++)
            {
                for(j=0;j<d;j++)
                {
                    if((i+1)%d!=(j+1)%d){
                    strncpy(data+t,disk[j]+i*s,s);
                    t+=s;
                    }
                }
            }
            sum=t/4;
            if(t%4) sum++;
            for(i=0;i<sum;i++)
            hex(data+4*i,text+i);
            printf("Disk set %d is valid, contents are: %s\n",count++,text);
        }
        else printf("Disk set %d is invalid.\n",count++);
    }
}