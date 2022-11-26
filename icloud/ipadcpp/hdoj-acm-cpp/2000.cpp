#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
char a,b,c;
char d[100];
int main()
{
    //ifstream cin("in.txt");ofstream cout("out.txt");
    while(cin>>a>>b>>c){
        d[1]=a;
        d[2]=b;
        d[3]=c;
        sort(d+1,d+1+3);
        for(int i=1;i<=3;++i) {
            cout<<d[i];
            if(i!=3) cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
