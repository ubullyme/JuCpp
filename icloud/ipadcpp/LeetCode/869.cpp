#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
string b[31]={"1","2","4","8","16","23","46","128","256","125","0124","0248","0469","1289","13468","23678","35566","011237","122446","224588","0145678","0122579","0134449","0368888","11266777","23334455","01466788","112234778","234455668","012356789","0112344778"};
int main(){
    string n;
    cin>>n;
    sort(n.begin(),n.end());
    for(int i=0;i<=30;i++){
        if(n==b[i]){
            cout<<"true"<<endl;
            return 0;
        }
    }
    cout<<"flase"<<endl;
    return 0;
}