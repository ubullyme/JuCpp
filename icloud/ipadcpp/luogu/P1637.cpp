#include <iostream>
#include <algorithm>
using namespace std;
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _rep_(i,a,b) for(int i=(a);i>=(b);--i)
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _idea(i,a,b) for(int i=(a);i<=b;++i)
typedef long long ll;
const int MAXN=5e5+5;
struct Node{
    ll val;
    ll id;
}aux[MAXN];
Node tree[MAXN];
int n;
inline ll lowbit(ll x){return x&-x;}
void add(ll x,ll d){
    while(x<=n){
        tree[x].val+=d;
        x+=lowbit(x);
    }
}
ll sum(ll x){
    ll ans=0;
    while(x>0){
        ans+=tree[x].val;
        x-=lowbit(x);
    }
    return ans;
}
bool cmp(Node a,Node b) { return a.val>b.val; }
bool cmp2(ll a,ll b) { return a>b; }
ll a[MAXN];
ll pre[MAXN];
ll ord[MAXN];



int main(){
    scanf("%d",&n);
    _rep(i,1,n) {tree[i].val=lowbit(i);}
    _rep(i,1,n) {scanf("%lld",&a[i]);aux[i].val=a[i];aux[i].id=i;}

    //sort(aux+1,aux+n+1,cmp);
    //int k=1;
    //_rep(i,1,n) if(aux2[i-1]==aux2[i])  aux[k].val=aux2[i];
    //对aux去重
    sort(aux+1,aux+1+n,cmp);
    _rep(i,2,n) if(aux[i-1].val==aux[i].val) {add(aux[i-1].id,-1);aux[i-1].id=0;}
    //_rep(i,1,n) cout<<aux[i].val<<" ";cout<<endl;
    _rep(i,1 && aux[i].id!=0,n) {
        pre[aux[i].id]=sum(aux[i].id-1);add(aux[i].id,-1);
    }
    _rep(i,1,n) {tree[i].val=lowbit(i);}
    _rep_(i,n && aux[i].id!=0,1) {ord[aux[i].id]=sum(n)-sum(aux[i].id);add(aux[i].id,-1);}
    //_rep(i,1,n) cout<<pre[i]<<" ";cout<<endl;
    //_rep(i,1,n) cout<<ord[i]<<" ";cout<<endl;
    long long tot=0;
    _rep(i,2,n-1) tot+=pre[i]*ord[i];
    cout<<tot;
    return 0;
}
