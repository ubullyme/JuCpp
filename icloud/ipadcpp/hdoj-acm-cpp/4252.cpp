#include <iostream>
#include <fstream>
#include <stack>
#include <cstring>
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _for(i,a,b) for(int i=(a);i<(b);++i)
const int MAXN=1e5+5;

using namespace std;
int N;
int h[MAXN];
stack<int> s;
int main()
{

    //ifstream cin("in.txt");ofstream cout("out.txt");
    ios::sync_with_stdio(false);
    cout.tie(NULL); 
    int  Case=1;
    while(cin>>N){
        while(!s.empty()) s.pop();
        s.push(0);
        int cnt=0;
        _rep(i,1,N){
            cin>>h[i];
            if(s.empty()) s.push(i);
        }
        for(int i=1;i<=N;){
            if(h[s.top()]>h[i]){
                s.pop();
            }
            else if(h[s.top()]==h[i]){
                ++i;
            }
            else{
                s.push(i);
                ++cnt;
                ++i;
            }
        }
        printf("Case %d: %d\n",Case++,cnt);
    }
    return 0;
}
