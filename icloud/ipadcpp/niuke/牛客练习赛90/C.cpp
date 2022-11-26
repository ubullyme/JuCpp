#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
const int MAXN=1e6+9;
int n;
ll s;
ll a[MAXN];
ll aux[2*MAXN];
ll ans;
ll sum(int k,ll * a){
    ll ans=0;
    for(int i=1;i<=k;i++){ans+=a[i];}
    return ans;
}
bool cmp(ll a,ll b){
    return a>b;
}
int main(){
    cin>>n>>s;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        aux[i]=aux[i-1]+a[i];
    }
    for(int k=1;k<=n;k++){
        ans=0;
        for(int i=k;i<=n+k;i+=k){
             ans = max(ans, aux[min(n, i)] - i / k * s);
        }
        cout<<ans<<endl;
    
    }
    return 0;
}
