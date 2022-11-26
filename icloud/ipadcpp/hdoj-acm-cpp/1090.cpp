#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //ifstream cin("in.txt");ofstream cout("out.txt");
    int n;
    int a,b;
    cin>>n;
    while(n--){
        cin>>a>>b;
        cout<<a+b<<endl;
    }
    return 0;
}
