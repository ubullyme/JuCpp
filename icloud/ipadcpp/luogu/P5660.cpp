#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string s;
    cin>>s;
    int ans=0;
    while(s.find("1")!=s.npos){
        s[s.find("1")]='0';
        ++ans;
    }
    cout<<ans;
    return 0;
}