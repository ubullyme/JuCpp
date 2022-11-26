#include <iostream>
#include <fstream>
#include <cmath>
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _for(i,a,b) for(int i=(a);i<(b);++i)

using namespace std;
int T;
int n,m;
inline int RAND(int a,int b) {return ((rand() % (b-a+1))+ a);}
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    //ifstream cin("in.txt");
    ofstream cout("right_in.txt");
    T=RAND(1,100);
    cout<<T<<endl;
    while(T--){
        n=RAND(1,10);
        m=RAND(1,10);
        cout<<n<<" "<<m<<endl;
        _rep(i,1,n){
            _rep(j,1,m){
                cout<<RAND(1,10)<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
