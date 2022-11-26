#include <iostream>
#include <cmath>
using namespace std;
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _for(i,a,b) for(int i=(a);i<(b);++i)
inline int readint(){int x;scanf("%d",&x);return x;}
const int MAXN=1e5 +10;
//int s[MAXN],sum[MAXN<<2],add[MAXN<<2];

long long s[MAXN];
long long sum[MAXN<<2];
long long add[MAXN<<2];

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

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


int n;
int m;
int opt;
int l,r,k,d;
int main(){
    n=readint();
    m=readint();  
    //build(1,n,1);
    _rep(i,1,n) s[i]=readint();
    while(m--){
        opt=readint();
        if(opt==1){
            l=readint();
            r=readint();
            k=readint();
            d=readint();
            update(l,l,k,1,n,1);
            //if(r>l) 
            update(l+1,r,d,1,n,1);
            int N=r-l+1;
            //if(r!=n) 
            update(r+1,r+1,-(k+(N-1)*d),1,n,1);
        }
        else{
            int ch=readint();
            cout<<s[ch]+query(1,ch,1,n,1)<<endl;
        }
    }
    return 0;
}
