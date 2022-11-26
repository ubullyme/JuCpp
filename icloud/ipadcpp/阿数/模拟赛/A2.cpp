//开灯问题
#include <stdio.h>
#include <string.h>
#define maxn 1010    //定义一个稍比1000大的数组
int a[maxn];
int main()
{
	int n, k, first = 1;       
	while(~scanf("%d%d",&n,&k)){
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= k; i++)   
            for(int j = 1; j <=n; j++)
                if(j % i == 0)
                    a[j] = !a[j];
        for (int i = 1; i <= n; i++)
        {
                if(a[i]){
                if(first)
                    first = 0;
                else
                    printf(" ");
                printf("%d",i);
            }
        }
        printf("\n");
    }
	return 0;
}
