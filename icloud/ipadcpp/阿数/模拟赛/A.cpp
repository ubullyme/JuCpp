#include <iostream>
#include <cstring>
static int data[1006];
using namespace std;
int main()
{
    int n,k;
    while(~scanf("%d %d",&n,&k)){
        memset(data,0,sizeof(data));
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= k; j++)
            {
                if(i % j == 0){
                    if(data[i] == 0)
                        data[i] = 1;
                    else data[i] = 0;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            if(data[i] == 1)
            if(i!=n)
                printf("%d ",i);
            else 
                printf("%d",i);
        }
        cout<<endl;
    }
}