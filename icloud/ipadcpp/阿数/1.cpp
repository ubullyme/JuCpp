#include <iostream>
#include <cstring>
using namespace std;
int num;
int main(){
    int n,len;
    string ans;
    getline(cin,ans);
    len=ans.size();
    for(int i=0;i<=len-1;i++){
        if(ans[i]<='9' && ans[i] >='0') num++;
    }
    cout<<num;
    return 0;
}