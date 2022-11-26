#include <iostream>
#include <fstream>
#include <stack>
#include <cstring>
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _for(i,a,b) for(int i=(a);i<(b);++i)
const int MAXN =2e3+3;
int a[MAXN][MAXN],up[MAXN][MAXN];
int h[MAXN];
using namespace std;
int getAnswer(int n,int* h){
    int ans=0;
    stack<int> s;
    s.push(0);
    for(int i=1;i<=n+1;++i){
        while(h[i]<h[s.top()]){
            int cur=h[s.top()];
            s.pop();
            ans=max(ans,cur*(i-h[s.top()]-1));
        }
        s.push(i);
    }
    return ans;
}
void print(int up[MAXN][MAXN],int n,int m){
    _rep(i,1,n){
        _rep(j,1,m){
            cout<<up[i][j]<<" ";
        }
        cout<<endl;
    }
}
void print(int up[MAXN],int m){

        _rep(j,1,m){
            cout<<up[j]<<" ";
        }
        cout<<endl;
    
}
int main()
{
ios::sync_with_stdio(false);
cout.tie(NULL);
    ifstream cin("in.txt");ofstream cout("out.txt");
    int T;
    cin>>T;
    while(T--){          
        int n,m;
        cin>>n>>m;
        int ans=-1;
        _rep(i,1,n){
            _rep(j,1,m) {
                cin>>a[i][j];
                if(i==1) continue;
                up[i][j] = (a[i][j]>=a[i-1][j]);
            }
        }
        //print(up,n,m);
        _rep(i,1,n){
            _rep(j,1,m){
                if(up[i][j]==0) h[j]=1;
                else h[j]++;

            }
            //print(h,m);
            ans=max(ans,getAnswer(m,h));
        }
        cout<<ans<<'\n';
        memset(h,0,sizeof(h));
    }
    return 0;
}
