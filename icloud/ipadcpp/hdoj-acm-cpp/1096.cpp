#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //ifstream cin("in.txt");ofstream cout("out.txt");
    int n;
    
    int a;
    cin>>n;
    while(n--){
        int N;
        int ans=0;
        cin>>N;
        while(N--){
            cin>>a;
            ans+=a;
        }
        cout<<ans<<endl;
        if(n) cout<<endl;
    }
    return 0;
}
