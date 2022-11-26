#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //ifstream cin("in.txt");ofstream cout("out.txt");
    int n,a,b;
    while(cin>>n){
        b=0;
        while(n--){
            cin>>a;
            b+=a;
        }
        cout<<b<<endl;
    }
    return 0;
}
