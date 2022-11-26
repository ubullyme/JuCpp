#include <iostream>
#include <cmath>
using namespace std;
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _for(i,a,b) for(int i=(a);i<(b);++i)
inline int readint(){int x;scanf("%d",&x);return x;}
const int MAXN=1e5 +10;

int s[MAXN],sum[MAXN<<2],add[MAXN<<2];
int n,m;

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


int main()
{
    
    n=readint();m=readint();
    for(int i=1;i<=n;i++) s[i]=readint();
    int type,L,R,K,D,ask;
    while(m--)
    {
        type=readint();
        if(type==1)
        {
            //in(L),in(R),in(K),in(D);
            L=readint();R=readint();K=readint();D=readint();
            //update(1,1,n,L,L,K);
            update(L,L,K,1,n,1);
            if(R>L) //update(1,1,n,L+1,R,D);
            update(L+1,R,D,1,n,1);
            int N=R-L+1;
            if(R!=n) //update(1,1,n,R+1,R+1,-(K+(N-1)*D));
            update(R+1,R+1,-(K+(N-1)*D),1,n,1);
        }
        else
        {
            //in(ask);
            ask=readint();
            printf("%d\n",s[ask]+query(1,ask,1,n,1));
        }
    }
    return 0;
}
