#include <iostream>
#include <fstream>
#include <cstring>
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define MAXN 105
const int mod = 1e9+7;
using namespace std;
int MatrixN ;
inline long long read(){
	long long a=0;int f=0;char p=getchar();
	while(!isdigit(p)){f|=p=='-';p=getchar();}
	while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48);p=getchar();}
	return f?-a:a;
}
struct Matrix{
    long long m[MAXN][MAXN];
    Matrix(){memset(m,0,sizeof(m));}
    void MatrixInit(){for(int i=1;i<=MatrixN;++i) m[i][i]=1;}
    void MatrixInput() {
        for(int i=1;i<=MatrixN;++i)
        for(int j=1;j<=MatrixN;++j)
        m[i][j]=read();
    }
    void MatrixPrint(){
        for(int i=1;i<=MatrixN;putchar('\n'),++i)
        for(int j=1;j<=MatrixN;++j)
        printf("%lld ",m[i][j]);
    }
};
Matrix Multi(Matrix a,Matrix b){
    Matrix res;
    for(int i=1;i<=MatrixN;++i)
    for(int k=1;k<=MatrixN;++k)
    for(int j=1;j<=MatrixN;++j)//让j连续 更快一点
    res.m[i][j]=(res.m[i][j]+a.m[i][k]*b.m[k][j]) % mod;
    return res;
}
Matrix fpow(Matrix a,long long k){
    Matrix res;
    res.MatrixInit();
    while(k){
        if(k&1) res=Multi(res,a);
        a=Multi(a,a);
        k>>=1;
    }
    return res;
}
int main()
{
    long long k;
    scanf("%d %lld",&MatrixN,&k);
    Matrix my;
    my.MatrixInput();
    my=fpow(my,k);
    my.MatrixPrint();
    return 0;
}

