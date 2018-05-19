#include<stdio.h>

int main(void)
{
    char a[9][9];
    int i,j,x,y,flag=1;
    for(i=0;i<9;i++)
    scanf("%s%s%s",&a[i][0],&a[i][3],&a[i][6]);
    scanf("%d%d",&x,&y);
    while(x>3) x-=3;
    while(y>3) y-=3;
        for(i=(x-1)*3;i<x*3;i++)
            for(j=(y-1)*3;j<y*3;j++)
                if(a[i][j]=='.') {a[i][j]='!';flag=0; }
    if(flag)
        for(i=0;i<9;i++)
            for(j=0;j<9;j++)
                if(a[i][j]=='.') a[i][j]='!';
    for(i=0;i<9;i++)
        {
            if(i%3==0&&i) printf("\n");
            for(j=0;j<9;j++)
            {
                if(j%3==0&&j) printf(" ");
                printf("%c",a[i][j]);
            }
            printf("\n");
        }
    return 0;
}
