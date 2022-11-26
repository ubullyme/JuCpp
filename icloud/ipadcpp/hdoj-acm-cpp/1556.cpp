#include <iostream>
#include <fstream>
#include <cstring>
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define MAXN 100005

using namespace std;
int arr[MAXN];
int N,a,b;
int main()
{
ios::sync_with_stdio(false);
cout.tie(NULL);
//ifstream cin("in.txt");ofstream cout("out.txt");
    while(cin>>N){
        if(N==0) break;
       _rep(i,1,N){
            cin>>a>>b;
            arr[a]+=1;
            arr[b+1]-=1;
        }
        _rep(i,2,N) arr[i]+=arr[i-1];
        _rep(i,1,N) if(i==N) cout<<arr[i]; else cout<<arr[i]<<" ";
        cout<<endl;
        memset(arr,0,sizeof(arr));
    }
    return 0;
}
