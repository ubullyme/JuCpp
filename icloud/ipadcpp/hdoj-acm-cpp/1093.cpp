#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //ifstream cin("in.txt");ofstream cout("out.txt");
    int n;
    cin>>n;
    int a,b;
    while(n--){
        b=0;
        int N;
        cin>>N;
        while(N--){
            cin>>a;
            b+=a;
        }
        cout<<b<<endl;
    }
    return 0;
}
