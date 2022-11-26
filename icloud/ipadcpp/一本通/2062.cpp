#include <iostream>
#include <limits.h>
using namespace std;
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _for(i,a,b) for(int i=(a);i<(b);++i)
inline int readint(){int x;scanf("%d",&x);return x;}
const int piaojia=10;
int main(){
    int x=readint();
    cout<<x<<" "<<piaojia*x;
    return 0;
}