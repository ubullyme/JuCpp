#include<stdio.h>
#include<string.h>
int d[110][110];
int main()
{
    int n,i,j,max,k,sum,t;
    while(~scanf("%d",&n)){
        memset(d,0,sizeof(d));
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++){
                scanf("%d",&d[i][j]);
                d[i][j]+=d[i-1][j];
            }
        max=d[1][1];
        for(i=1; i<=n; i++)
            for(j=i; j<=n; j++){
                sum=0;
                for(k=1; k<=n; k++){
                    t=d[j][k]-d[i-1][k];
                    sum+=t;
                    if(sum>=max)
                        max=sum;
                    if(sum<0)
                        sum=0;
                }
            }
        printf("%d\n",max);
    }
}