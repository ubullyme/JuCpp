#include <iostream>
#include <algorithm>
using namespace std;
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _rep_(i,a,b) for(int i=(a);i>=(b);--i)
#define _for(i,a,b) for(int i=(a);i<(b);++i)
//inline int readint(){int x;scanf("%d",&x);return x;}
const int MAXN=5e5+5;
int tree1[MAXN],tree2[MAXN];
int L[MAXN],R[MAXN];
int A[MAXN],_A[MAXN];
int n,m;
inline int lowbit(int x){return x&-x;}
inline int _Q(int val){//查询A[i]对应的映射值 
	return lower_bound(_A+1,_A+m+1,val)-_A;
}
void add(int* tree,int x,int d){
    while(x<=n){
        tree[x]+=d;
        x+=lowbit(x);
    }
}
int sum(int* tree,int x){
    int ans=0;
    while(x>0){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin>>n;
    _rep(i,1,n){
        cin>>A[i];
        _A[i]=A[i];
    }
    sort(_A+1,_A+n+1);
    m=unique(_A+1,_A+n+1)-(_A+1);
    for(int i=1;i<=n;i++){
		add(tree1,_Q(A[i]),1);
		L[i]=sum(tree1,_Q(A[i])-1);
    }
    for(int i=n;i>=1;--i){
		add(tree2,_Q(A[i]),1);
		R[i]=n-i-(sum(tree2,_Q(A[i]))-1);
    }
    long long ans=0;
    for(int i=2;i<n;i++) ans+=L[i]*R[i];
    cout<<ans;
    return 0;
}
