#include <iostream>
using namespace std;
const int Max=1e4+5;
int a[Max];
int aux[Max];
void init(int n){
    for(int i=1;i<=n;i++){
        a[i]=i;
        aux[i]=0;
    }
}

int find_set(int x){
    return x==a[x]?x:find_set(a[x]);
}
int find_set2(int x){
    int r=x;
    while(a[x]!=r) r=a[r];//找到根
    int i=x,j;
    while(i!=r) {j=a[i];a[i]=r;i=j;}//将所有节点的祖先变成根节点
    return r;
}



void union_set(int x,int y){
    x=find_set(x);
    y=find_set(y);
    if(aux[x]==aux[y]&& x != y){
        aux[x]=aux[x]+1;
        a[y]=x;//aux[y]还是0；
    }
    else{
        if(aux[x]<aux[y]) a[x]=y;//x的长度短 就合并到y
        else a[y]=x;
    }
}
bool isSame(int x,int y){
    return find_set(a[x])==find_set(a[y]);
}
int main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    init(n);
    int ch;
    while(m--){
        cin>>ch;
        if(ch==1){
            int x,y;
            cin>>x>>y;
            union_set(x,y);
        }
        else{
            int x,y;
            cin>>x>>y;
            if(isSame(x,y)) cout<<"Y"<<endl;
            else cout<<"N"<<endl;
        }
    }
    return 0;
}