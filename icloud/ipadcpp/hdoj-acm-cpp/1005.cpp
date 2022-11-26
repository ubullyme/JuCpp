#include <iostream>
#include <fstream>
using namespace std;
int f[60];
int A,B,n;
int main(){
    //ifstream cin("in.txt");ofstream cout("out.txt");
    f[1]=f[2]=1;
    while(cin>>A>>B>>n && (A||B||n)){
        for(int i=3;i<=49;++i){
            f[i]=(A*f[i-1]+B*f[i-2])%7;
        }
        cout<<f[n%49]<<endl;
    }
    return 0;
}