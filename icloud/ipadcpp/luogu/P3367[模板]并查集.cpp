#include <iostream>
using namespace std;
const int Max=1e4+5;
int a[Max];
void init(int n){
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
}
int find(int x){
    return x==a[x]?x:find(a[x]);//找到最祖先的地方
}
int find_set(int x){
    if(x!=a[x]) a[x]=find_set(a[x]);
    return a[x];
}
void Myunion(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y) a[x]=a[y];//x的祖先变成y的祖先 合并
}
bool isSame(int x,int y){
    x=find(x);
    y=find(y);
    return x==y;
}
int main(){
    int n,m;
    cin>>n>>m;
    init(n);
    int ch;
    while(m--){
        cin>>ch;
        if(ch==1){
            int x,y;
            cin>>x>>y;
            Myunion(x,y);
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