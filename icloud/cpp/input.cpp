
//#define LOCAL

#include <iostream>
using namespace std;
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    int a,b;
    while(~scanf("%d%d",&a,&b)){
        printf("%d\n",a+b);
    }
    return 0;
}