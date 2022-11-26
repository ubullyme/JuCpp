#include <iostream>
#include <limits.h>
using namespace std;
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _for(i,a,b) for(int i=(a);i<(b);++i)
const int MAXN=1e5+5;
int d[MAXN];//记录第i个最大子序列和
int sum[MAXN];
int t;
int l,r,rl;
int main(){
    cin>>t;
    _rep(tt,1,t){
        int maxn=INT_MIN;
        int l=1,r=1,rl=1;
        int n;cin>>n;
        _rep(i,1,n) cin>>sum[i];
        d[1]=sum[1];
        _rep(i,2,n){
            if(d[i-1]>=0) {
                d[i]+=d[i-1]+sum[i];
            }
            else{
                d[i]+=sum[i];
                l=i;
            } 
            if(d[i]>=maxn) {maxn=d[i];r=i;rl=l;}
        }
        _rep(i,1,n) cout<<d[i]<<" ";
        cout<<endl;
		cout<<"Case "<<tt<<':'<<endl;
		cout<<maxn<<' '<<rl<<' '<<r<<endl;
		if(tt!=t) cout<<endl;

    }
    return 0;
}
