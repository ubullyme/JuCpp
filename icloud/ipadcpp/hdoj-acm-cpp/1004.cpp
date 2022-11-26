#include <iostream>
#include <map>
#include <cstring>
#include <limits.h>
using namespace std;

map<string,int> a;
string temp;
int main(){
    int n;
    while(true){
        int maxn=INT_MIN;
        cin>>n;if(n==0) break;
        for(int i=1;i<=n;i++){
            long long maxn=INT_MIN;
            string s;
            cin>>s;
            a[s]++;
        }
        map<string,int>::iterator id;
        for(id=a.begin();id!=a.end();id++){
            if(id->second>maxn){
                maxn=id->second;
                temp=id->first;
           }
        }
        cout<<temp<<endl;
        a.clear();
    }
    return 0;
}