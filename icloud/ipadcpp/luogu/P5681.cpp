#include <iostream>
long long a,b,c;
int main(){
    std::cin>>a>>b>>c;
    a*a>b*c?puts("Alice"):puts("Bob");
    return 0;
}