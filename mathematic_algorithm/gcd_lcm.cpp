#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int a, int b){
    // return the greatest common divisor.
    if(b==0) return a;
    if(a<b) return gcd(a, b%a);
    else return gcd(b, a%b);
}

int lcm(int a, int b){
    // return the least common multiper.
    return (a*b)/gcd(a, b);
}

int main(){
    int a, b, res;
    while(~scanf("%d", &a)){
        scanf("%d", &b);
        res = gcd(a, b);
        printf("%d", res);
    }
    return 0;
}
