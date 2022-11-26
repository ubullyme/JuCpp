#include <iostream>
#include <fstream>
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _for(i,a,b) for(int i=(a);i<(b);++i)

using namespace std;
int f[90]={0,1,2,3,4,6};
int main()
{
ios::sync_with_stdio(false);
cout.tie(NULL);
    //ifstream cin("in.txt");ofstream cout("out.txt");
    int n;
    for(int i=6;i<=70;++i){
        f[i]=f[i-3]+f[i-1];
    }
    while(true){
        cin>>n;
        if(n==0) break;
        cout<<f[n]<<endl;
    }
    return 0;
}
