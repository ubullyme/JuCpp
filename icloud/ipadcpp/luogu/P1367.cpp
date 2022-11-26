#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    int x;
    int d;
    int id;
}ants[100005],bnts[100005];
int order[100005];
int n,t;
bool cmp(Node x,Node y){
    return x.x<y.x;
}

void input(){
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        int x,d;

        cin>>x>>d;
        ants[i]=(Node){x,d,i};
        bnts[i]=(Node){x+t*d,d,i};
        
    }
}

void solve(){
    sort(ants+1,ants+n+1,cmp);
    for(int i=1;i<=n;i++){
        order[ants[i].id]=i;
    }

    sort(bnts+1,bnts+n+1,cmp);
    for(int i=1;i<n;i++){
        if(bnts[i].x==bnts[i+1].x) bnts[i].d=bnts[i+1].d=0;
        
    }
}

void output(){

    for(int i=1;i<=n;i++){
        cout<<bnts[order[i]].x<<" "<<bnts[order[i]].d<<endl;
    }
    
}
int main(){

    input();
    solve();
    output();
    return 0;
}