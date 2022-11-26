#include <iostream>
using namespace std;
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _for(i,a,b) for(int i=(a);i<(b);++i)
inline int readint(){int x;scanf("%d",&x);return x;}
const int MAXN=5e5+5;
int tree[MAXN];
int n,m;
inline int lowbit(int x){return x&-x;}
void add(int x,int d){while(x<=n){tree[x]+=d;x+=lowbit(x);}}
int sum(int x){
    int ans=0;
    while(x>0){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
int main(){
    n=readint();
    m=readint();
    _rep(i,1,n) {int d=readint();add(i,d);}
    while(m--){
        int opt=readint();            
        int x=readint();
        int k=readint();
        if(opt==1) add(x,k);
        else printf("%d\n",sum(k)-sum(x-1));
    }
    return 0;
}
