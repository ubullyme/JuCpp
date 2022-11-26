#include <iostream>
#include <fstream>
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _for(i,a,b) for(int i=(a);i<(b);++i)

using namespace std;
const int MAXN = 1e8;
int a[MAXN];
long long GCD(long long num1,long long num2)
{
if(num1%num2==0)
return num2;
else return  GCD(num2,num1%num2);
}
long long LCM(long long a,long long b)
{
long long temp_lcm;
temp_lcm=a*b/GCD(a,b);//最小公倍数等于两数之积除以最大公约数
return temp_lcm;
}
int main()
{
ios::sync_with_stdio(false);
cout.tie(NULL);
//ifstream cin("in.txt");ofstream cout("out.txt");
    int n;
    cin>>n;
    _rep(t,1,n){
        int cnt;
        long long ans;
        cin>>cnt;
        _rep(i,1,cnt) cin>>a[i];
        ans=a[1];
        _rep(i,2,cnt) ans=LCM(ans,a[i]);
        cout<<ans<<endl;
    }
    return 0;
}
