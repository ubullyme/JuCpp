#include <iostream>
using namespace std;
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define lowbit(x) ((x)&-(x))
inline int readint(){int x;scanf("%d",&x);return x;}
const int MAXN=1e5+5;
int tree[MAXN];
int n;
int t;
void add(int x,int d){
    while(x<=n){
        tree[x]+=d;
        x+=lowbit(x);
    }
}
int sum(int x){
    int sum=0;
    while(x>0){
        sum+=tree[x];
        x-=lowbit(x);
    }
    return sum;
}
int main(){
    t=readint();
    while(t--){
        n=readint();
        _rep(i,1,n) tree[i]=readint();
        add(1,1);
        _rep(i,1,n) cout<<tree[i]<<" ";
    }
    return 0;
}
