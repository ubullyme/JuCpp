#include <iostream>
#include <fstream>
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _for(i,a,b) for(int i=(a);i<(b);++i)

using namespace std;
int GCD(int num1,int num2)
{
if(num1%num2==0)
return num2;
else return  GCD(num2,num1%num2);
}
int LCM(int a,int b)
{
int temp_lcm;
temp_lcm=a*b/GCD(a,b);//最小公倍数等于两数之积除以最大公约数
return temp_lcm;
}
int main()
{
ios::sync_with_stdio(false);
cout.tie(NULL);
    //ifstream cin("in.txt");ofstream cout("out.txt");
    int a,b;
    while(cin>>a>>b){
        cout<<LCM(a,b)<<endl;
    }
    return 0;
}
