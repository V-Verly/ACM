#include <stdio.h>
int main(void)
{
    int t,i,n,r;
    double s;
    char a[85];
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        s=0;
        memset(a,0,sizeof(a));
        gets(a);
        n=strlen(a);
        while(i<n)
        {
            r=1;
            switch(a[i])
            {
                case 'C':{
                    if(i<(n-1)&&a[i+1]>='1'&&a[i+1]<='9') 
                    {
                        r=0;
                while(i<(n-1)&&a[i+1]>='1'&&a[i+1]<='9')
                      {  
                          r=r*10;
                          r+=a[++i]-'0';
                      }
                        i++;
                    }
                    else i++;
                    s+=12.01*r;
                    break;
                }
                case 'H': {
                    if(i<(n-1)&&a[i+1]>='1'&&a[i+1]<='9') 
                    {
                        r=0;
                while(i<(n-1)&&a[i+1]>='1'&&a[i+1]<='9')
                        {  
                          r=r*10;
                          r+=a[++i]-'0';
                      }
                        i++;
                    }
                    else i++;
                    s+=1.008*r;
                    break;
                }
                case 'O': {
                    if(i<(n-1)&&a[i+1]>='1'&&a[i+1]<='9') 
                    {
                        r=0;
                while(i<(n-1)&&a[i+1]>='1'&&a[i+1]<='9')
                        {  
                          r=r*10;
                          r+=a[++i]-'0';
                      }
                        i++;
                    }
                    else i++;
                    s+=16.00*r;
                    r++;
                    break;
                }
                case 'N': {
                    if(i<(n-1)&&a[i+1]>='1'&&a[i+1]<='9') 
                    {
                        r=0;
                while(i<(n-1)&&a[i+1]>='1'&&a[i+1]<='9')
                        {  
                          r=r*10;
                          r+=a[++i]-'0';
                      }
                        i++;
                    }
                    else i++;
                    s+=14.01*r;
                    r=1;
                    break;
                }
                default:
                i++;break;
            }
        }
        i=0;
        printf("%.3f\n",s);
    }
    return 0;
}