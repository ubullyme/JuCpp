#include <iostream>
#include <fstream>
#include <cmath>
#define PI 3.1415927
using namespace std;

int main()
{
    //ifstream cin("in.txt");ofstream cout("out.txt");
    double r;
    while(cin>>r){
        //cout<<pow(r,3);
        double ans=PI*r*r*r*4/3;
        printf("%.3lf\n",ans);
    }
    return 0;
}
