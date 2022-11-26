#include <iostream>
using namespace std;
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _for(i,a,b) for(int i=(a);i<(b);++i)
inline int readint(){int x;scanf("%d",&x);return x;}
const int MAXN=1e5 +10;
long long sum[4*MAXN];
long long add[4*MAXN];//add是lazy标签
int t,n,m;
void push_up(int rt){//向上更新
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void push_down(int rt,int m){
    if(add[rt]){
        add[rt<<1]+=add[rt];
        add[rt<<1|1]+=add[rt];
        sum[rt<<1]+=(m-(m>>1))*add[rt];
        sum[rt<<1|1]+=(m>>1)*add[rt];
        //向下更新
        add[rt]=0;
    }
}
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
void build(int l,int r,int rt){
    add[rt]=0;
    if(l==r){
        scanf("%lld",&sum[rt]);
        return;
    }
    int mid=(l+r)>>1;
    build(lson);
    build(rson);//建树到最底层 退出递归到倒数第二层 向下跟新一层 在退出一层 再向下更新一层 完成向上更新区间和
    push_up(rt);
    
}

void update(int a,int b,long long c,int l,int r,int rt){
    if(a<=l && b>=r){
        sum[rt]+=(r-l+1)*c;//更新区间和
        add[rt]+=c;//添加lazy标记
        return;
    }
    push_down(rt,r-l+1);//向下更新被修改的区间
    int mid=(l+r)>>1;
    if(a<=mid) update(a,b,c,lson);
    if(b>mid) update(a,b,c,rson);
    push_up(rt);
}
long long query(int a,int b,int l,int r,int rt){
    if(a<=l && b>=r) return sum[rt];//被查找区间 已经包含 
    //没有被包含 需要访问下面的 所以向下更新
    push_down(rt,r-l+1);
    int mid=(l+r)>>1;
    long long ans=0;
    if(a<=mid) ans+=query(a,b,lson);
    if(b>mid) ans+=query(a,b,rson);
    return ans;
}
int main(){
    t=readint();
    while(t--){
        n=readint();
        build(1,n,1);
        m=readint();
        while(m--){
            int l=readint();
            int r=readint();
            int x=readint();
            update(l,r,x,1,n,1);
        }
        _rep(i,1,n) if(i!=n) cout<<query(i,i,1,n,1)<<" ";else cout<<query(i,i,1,n,1)<<endl;
    }
    return 0;
}
