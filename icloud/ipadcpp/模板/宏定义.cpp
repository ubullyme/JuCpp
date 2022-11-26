#include <iostream>
using namespace std;
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _for(i,a,b) for(int i=(a);i<(b);++i)
inline int readint(){int x;scanf("%d",&x);return x;}



int main(){
    int a,b,c;
    a=readint();
    b=readint();
    c=readint();
    _rep(i,a,b) cout<<c<<" ";cout<<endl;
    _for(i,a,b) cout<<c<<" ";cout<<endl;
    return 0;
}