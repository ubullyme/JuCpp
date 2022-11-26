#include <iostream>
using namespace std;
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _for(i,a,b) for(int i=(a);i<(b);++i)
inline int readint(){int x;scanf("%d",&x);return x;}
const int MAXN=1e5+5;
int t;
int m,n;
int a[MAXN];
int aux[MAXN];
int main(){
    t=readint();
    while(t--){
        n=readint();
        _rep(i,1,n) a[i]=readint();
        m=readint();
        while(m--){
            int l=readint();
            int r=readint();
            int x=readint();
            aux[l]+=x;
            aux[r+1]-=x;
        }
        _rep(i,2,n) aux[i]+=aux[i-1];
        _rep(i,1,n) {a[i]+=aux[i];if(i!=n)cout<<a[i]<<" ";else cout<<a[i]<<endl;}
    }
    return 0;
}