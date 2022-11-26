#include <iostream>
#include <limits.h>
using namespace std;
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _for(i,a,b) for(int i=(a);i<(b);++i)
inline int readint(){int x;scanf("%d",&x);return x;}
const int MAXN=2e5+5;
int d[MAXN];//记录第i个最大子序列和
long long sum[MAXN];
int t;
int maxn=INT_MIN;
int main(){
    //t=readint();
    //_rep(tt,1,t){
        int n=readint();
        _rep(i,1,n) sum[i]=readint();
        d[1]=sum[1];
        _rep(i,2,n){
            if(d[i-1]>=0) {
                d[i]+=d[i-1]+sum[i];
            }
            else{
                d[i]+=sum[i];
            } 
            if(d[i]>maxn) {maxn=d[i];}
        }

        cout<<maxn<<endl;        
    //}
    return 0;
}
