#include <iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int f[40];

struct data
{
    int jz[2][2];
};

data p={0,1,
        1,1};
 data q={1,0,
        0,1};
int jl;
void get()
{
    f[0]=0,f[1]=1;int i;
    for(i=2;;i++)
        {
            f[i]=f[i-1]+f[i-2];
            if(f[i]>=100000000)
            {jl=i-1;break;}
        }
}

int hh(int n)
{
    return pow(10,(log10(1/sqrt(5.0))+n*log10((1+sqrt(5.0))/2.0)-(int)(log10(1/sqrt(5.0))+n*log10((1+sqrt(5.0))/2.0))+3));
}

data jzcf(data a,data b)//矩阵相乘
{
    data c;
    for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
    {
        c.jz[i][j]=0;
        for(int k=0;k<2;k++)
        c.jz[i][j]+=(a.jz[i][k]*b.jz[k][j])%10000;
        c.jz[i][j]%=10000;
    }
    return c;
}

data quickpow(long long n)//和快速幂类似的矩阵连乘
{
    data m = p, b = q;
    while (n >= 1)
    {
    if (n & 1)
    b = jzcf(b,m);
    n = n >> 1;
    m = jzcf(m,m);
    }
    return b;
}

int main()
{
    long long  n;
    get();
    while(cin>>n)
    {
        if(n<=jl)cout<<f[n]<<endl;
        else
        {
            cout<<hh(n)<<"...";
            data x=quickpow(n);
            printf("%04d\n",x.jz[0][1]);
        }
    }
    return 0;
}
