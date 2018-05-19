#include <stdio.h>
struct command{
    char c[5];
    int r1,c1,r2,c2;
    int a,x[20];
}cmd[10000];
int n;
int simulate(int* r0,int* c0)
{
    int dr,dc;
    int i,j;
    for(i=0;i<n;i++)
    {
        if(cmd[i].c[0]=='E') 
        {
            if(cmd[i].r1==*r0&&cmd[i].c1==*c0) 
            *r0=cmd[i].r2,*c0=cmd[i].c2;
            else if(cmd[i].r2==*r0&&cmd[i].c2==*c0) 
            *r0=cmd[i].r1,*c0=cmd[i].c1;
        }
        else
        {
            dr=0;dc=0;
            for(j=0;j<cmd[i].a;j++)
            {
                if(cmd[i].c[0]=='D')
                {
                    if(cmd[i].c[1]=='R'&&cmd[i].x[j]==*r0) return 0;
                    if(cmd[i].c[1]=='C'&&cmd[i].x[j]==*c0) return 0;
                    if(cmd[i].c[1]=='R'&&cmd[i].x[j]<*r0) dr--;
                    if(cmd[i].c[1]=='C'&&cmd[i].x[j]<*c0) dc--;
                }
                else
                {
                    if(cmd[i].c[1]=='R'&&cmd[i].x[j]<=*r0) dr++;
                    if(cmd[i].c[1]=='C'&&cmd[i].x[j]<=*c0) dc++;    
                }
            }
            //printf("%d %d %d\n",i,dr,dc);
            *r0+=dr;
            *c0+=dc;
        }
    }
    return 1;
}
int main ()
{
    int r,c,s,t=0,e,i,j,r0,c0;
    while(scanf("%d%d%d",&r,&c,&n)!=EOF&&r)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",cmd[i].c);
            if(cmd[i].c[0]=='E') 
            scanf("%d%d%d%d",&cmd[i].r1,&cmd[i].c1,&cmd[i].r2,&cmd[i].c2);
            else
            {
                scanf("%d",&cmd[i].a);
                for(j=0;j<cmd[i].a;j++)
                scanf("%d",&cmd[i].x[j]);
            }
        }
        if(t) printf("\n");
        printf("Spreadsheet #%d\n",++t);
        scanf("%d",&e);
        while(e--)
        {
            scanf("%d%d",&r0,&c0);
            printf("Cell data in (%d,%d) ",r0,c0);
            if(!simulate(&r0,&c0)) printf("GONE\n");
            else printf("moved to (%d,%d)\n",r0,c0);
        }
    }
    return 0;
}
