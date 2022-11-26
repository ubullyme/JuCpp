#include <iostream>
#include <limits.h>
using namespace std;
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _for(i,a,b) for(int i=(a);i<(b);++i)
const int MAXN=1e5+5;
long long sum[MAXN];
long long ans;
int t;
int maxn=INT_MIN;
int l,r,rl;
void init(){
    maxn=INT_MIN;
    l=1;
    r=1;
    rl=1;
    ans=0;
}
int main(){
    cin>>t;
    _rep(tt,1,t){
        int n;
        cin>>n;
           init();
        _rep(i,1,n){
            cin>>sum[i];
            ans+=sum[i];
            if(ans>=maxn){
                maxn=ans;
                r=i;
                rl=l;
            }
            if(ans<0) {
                ans=0;
                l=i+1;   
            }
        }
		cout<<"Case "<<tt<<':'<<endl;
		cout<<maxn<<' '<<rl<<' '<<r<<endl;
		if(tt!=t) cout<<endl;
    }
    return 0;
}
