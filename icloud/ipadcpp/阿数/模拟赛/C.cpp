#include <iostream>
using namespace std;

int GCD(int a,int b)
{
    return a%b?GCD(b,a%b):b;
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        cout<<"Case "<<i<<": "<<GCD(a,b);
        if(i!=n) cout<<"\n";
    }


    return 0;
}