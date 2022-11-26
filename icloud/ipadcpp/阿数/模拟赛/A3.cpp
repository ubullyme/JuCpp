#include<iostream>
using namespace std;
bool trek[100];
int main()
{
    int n,k;
    while(cin>>n>>k){
        memset(trek,true,100*sizeof(bool));//这个函数的作用是让所有的都为true
        for(int i=2;i<=k;i++){
            int pos=i;
            while(pos<=n){
                trek[pos] = !trek[pos];  //反转
                pos+=i;     //找到所有的倍数
            }
        }
        for(int i=1;i<=n;i++){      //输出
            if(trek[i])  {
                if(i!=n)
                    cout<<i<<" ";
                else
                    cout<<i;
            }
        }
    }
    return 0;
}