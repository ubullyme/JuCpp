#include <iostream>
#include <algorithm>
using namespace std;
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _idea(i,a,b) for(int i=(a);i<=b;++i)
inline int readint(){int x;scanf("%d",&x);return x;}
const int MAXN=5e5+5;
struct Node{
    int val;
    int id;
}aux[MAXN];
Node tree[MAXN];
int n;
inline int lowbit(int x){return x&-x;}
void add(int x,int d){
    while(x<=n){
        tree[x].val+=d;
        x+=lowbit(x);
    }
}
void add2(int x,int d){
    while(x<=n){
        tree[x].id+=d;
        x+=lowbit(x);
    }
}
int sum(int x){
    int ans=0;
    while(x>0){
        ans+=tree[x].val;
        x-=lowbit(x);
    }
    return ans;
}

int sum2(int x){
    int ans=0;
    while(x>0){
        ans+=tree[x].id;
        x-=lowbit(x);
    }
    return ans;
}



bool cmp(Node a,Node b) { return a.val>b.val; }
int a[MAXN];
int pre[MAXN];
int tot;
int main(){
    n=readint();
    _rep(i,1,n) {tree[i].val=lowbit(i);}
    _rep(i,1,n) {a[i]=readint();aux[i].val=a[i];aux[i].id=i;}
    sort(aux+1,aux+n+1,cmp);
    _rep(i,1,n) {pre[aux[i].id]=sum(aux[i].id-1);add(aux[i].id,-1);}
    //_rep(i,1,n) cout<<pre[i]<<" ";cout<<endl;
    //_rep(i,1,n) add2(i,pre[i]);
    //_rep(i,1,n) if(aux[i].id!=1 && aux[i].id!=n){tot+=sum2(n)-sum2(aux[i].id);add2(aux[i].id,-pre[i]);}
     //           else {add2(aux[i].id,-pre[i]);}
    //_rep(i,aux[i].id,n) {pre[i]}
    _rep(i,1,n){
        if(pre[aux[i].id]!=0) {
            _rep(j,aux[i].id+1,n) tot+=min(pre[j],pre[aux[i].id]);
            pre[aux[i].id]=0;
        }
    }
    cout<<tot;
    return 0;
}
