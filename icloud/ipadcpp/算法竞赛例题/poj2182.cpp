#include <cmath>
#include <iostream>
using namespace std;


const int Max=10000;
int pre[Max];
int tree[4*Max];
int ans[Max];

void BuildTree(int n,int last_left){
    for(int i=last_left;i<last_left+n;i++){//循环走了n遍
        tree[i]=1;
    }
    while(last_left!=1){
        for(int i=last_left/2;i<last_left;i++){//last_left已经是最后一行了 没有子节点了 没必要加
            tree[i]=tree[i*2]+tree[2*i+1];
        }
        last_left=last_left/2;//刚好是上一行 就是满二叉树的性质
    }

}


int query(int u,int num,int last_left){
    //查询维护，num表示 查询的值是从左第num个
    tree[u]--;//元素处理过之后就删除 不在访问
    if(tree[u]==0 && u>=last_left){ //u要大last表示 在最后一行查询
        return u;
    }
    
    if(tree[u*2]<num){
        return query((u<<1)+1,num-tree[u<<1],last_left);//左边不够 查右边 num-tree去掉左边的个数 表示右边有几个数

    }
   // if(tree[u*2]>=num)
   else
    {
        return query(u<<1,num,last_left);
    }
    

    //return u;
}
int main(){
    int n;
    int last_left;
    int i;
    cin>>n;
    pre[1]=0;
    last_left=1<<(int(log(n)/log(2))+1);
    for(int i=2;i<=n;i++){
        cin>>pre[i];
    }
    BuildTree(n,last_left);
    for(int i=n;i>=1;i--){
        ans[i]=query(1,pre[i]+1,last_left)-last_left+1;//pre表示比prei小的数有pre个 那么pre+1就是表示prei是在这些没有处理的数中第prei大的数
        //找到这个数字 然后算出他的大小
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}


