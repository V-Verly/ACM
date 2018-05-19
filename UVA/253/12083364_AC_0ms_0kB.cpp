#include<stdio.h>
#include<string.h>
int main(void){
    char a[8],b[8],n[24][7];
    int i,j,flag,t[4]={1,2,4,3},s[6][6]={{0,1,2,3,4,5},{1,5,2,3,0,4},{2,5,4,1,0,3},{3,1,0,5,4,2},{4,0,2,3,5,1},{5,4,2,3,1,0}};
    while(~scanf("%6s%6s",a,b))
    {
        
        flag=0;
        for(i=0;i<6;i++){
            for(j=0;j<4;j++){
                n[i*4+j][0]=b[s[i][0]];
                n[i*4+j][5]=b[s[i][5]];
                n[i*4+j][1]=b[s[i][t[j%4]]];
                n[i*4+j][2]=b[s[i][t[(j+1)%4]]];
                n[i*4+j][4]=b[s[i][t[(j+2)%4]]];
                n[i*4+j][3]=b[s[i][t[(j+3)%4]]];
                n[i*4+j][6]='\0';
                //printf("%c%c%c%c%c%c\n", b[s[i][0]], b[s[i][j%4+1]], b[s[i][(j+1)%4+1]], b[s[i][(j+2)%4+1]], b[s[i][(j+3)%4+1]], b[s[i][5]]);
             //puts(n[i*4+j]);
            //printf("\n");
            }
        }
        for(i=0;i<24;i++){
            //puts(n[i]);
            //printf("\n");
           if(strcmp(n[i],a)==0) {flag=1;break;}
        }
        if(flag) printf("TRUE\n");
        else printf("FALSE\n");
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(n,0,sizeof(n));
    }
}