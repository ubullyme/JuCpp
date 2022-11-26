#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //ifstream cin("in.txt");ofstream cout("out.txt");
    int n,a,b;
    while(cin>>n){
        if(n==0)break;
        b=0;
        for(int i=1;i<=n;i++){
            cin>>a;
            b+=a;
        }
        cout<<b<<endl;
    }
    return 0;
}
