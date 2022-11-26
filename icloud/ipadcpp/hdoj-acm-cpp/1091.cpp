#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //ifstream cin("in.txt");ofstream cout("out.txt");
    int a,b;
    while(cin>>a>>b){
        if(a==0&&b==0)break;
        cout<<a+b<<endl;
        }
    return 0;
}
