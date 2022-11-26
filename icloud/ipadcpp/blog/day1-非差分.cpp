#include <iostream>
using namespace std;
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _for(i,a,b) for(int i=(a);i<(b);++i)
const int MAXN = 1e5 +6;
int t;
int m,n;
int a[MAXN];
int readint(){int x;scanf("%d",&x);return x;}
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
            _rep(i,l,r) a[i]+=x;
        }
        _rep(i,1,n) if(i!=n) cout<<a[i]<<" ";else cout<<a[i];
        cout<<endl;
    }
    return 0;
}

